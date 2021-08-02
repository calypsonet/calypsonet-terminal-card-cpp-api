/**************************************************************************************************
 * Copyright (c) 2021 Calypso Networks Association                                                *
 * https://www.calypsonet-asso.org/                                                               *
 *                                                                                                *
 * See the NOTICE file(s) distributed with this work for additional information regarding         *
 * copyright ownership.                                                                           *
 *                                                                                                *
 * This program and the accompanying materials are made available under the terms of the Eclipse  *
 * Public License 2.0 which is available at http://www.eclipse.org/legal/epl-2.0                  *
 *                                                                                                *
 * SPDX-License-Identifier: EPL-2.0                                                               *
 **************************************************************************************************/

#pragma once

/* Calypsonet Terminal Card */
#include "CardRequestSpi.h"
#include "CardResponseApi.h"
#include "ChannelControl.h"

namespace calypsonet {
namespace terminal {
namespace card {

using namespace calypsonet::terminal::card::spi;

/**
 * Reader able to transmit card requests and having control over the physical channel.
 *
 * <p>Backside of the <b>calypsonet::terminal::reader::CardReader</b> interface present in the
 * <b>Terminal Reader API</b>.
 *
 * <p>An adapter of this interface must also implement <b>CardReader</b>.
 *
 * <p>To use this API, simply cast a <b>CardReader</b> as a <b>ProxyReaderApi</b>.
 *
 * @since 1.0
 */
class ProxyReaderApi {
public:
    /**
     * Transmits a calypsonet::terminal::card::CardRequestSpi, applies the provided
     * calypsonet::terminal::card::ChannelControl policy and returns a
     * calypsonet::terminal::card::CardResponseApi.
     *
     * <p>The APDUs (calypsonet::terminal::card::spi::ApduRequestSpi) contained in the
     * calypsonet::terminal::card::CardRequestSpi are sent to the card, their responses
     * (calypsonet::terminal::card::ApduResponseApi) are added to a new list
     * (calypsonet::terminal::card::CardResponseApi).
     *
     * <p><b>Note:</b> in case of an error when sending an APDU (communication error, unexpected
     * status word), an calypsonet::terminal::card::AbstractApduException exception is thrown. Any
     * responses from previously transmitted APDU commands are attached to this exception.<br>
     * This allows the calling application to be tolerant to card tearing and to retrieve the partial
     * response to the calypsonet::terminal::card::CardRequestSpi or to have strict control over the
     * APDUs sent to the card (see
     * calypsonet::terminal::card::CardRequestSpi::stopOnUnsuccessfulStatusWord()).
     *
     * @param cardRequest The card request.
     * @param channelControl The channel control policy to apply.
     * @return A not null reference.
     * @throw IllegalArgumentException If one of the provided parameters is null.
     * @throw ReaderBrokenCommunicationException If the communication with the reader has failed.
     * @throw CardBrokenCommunicationException If the communication with the card has failed.
     * @throw UnexpectedStatusWordException If any of the APDUs returned an unexpected status word
     *        and the card request specified the need to check them.
     * @since 1.0
     */
    virtual const std::shared_ptr<CardResponseApi> transmitCardRequest(
        const std::shared_ptr<CardRequestSpi> cardRequest,
        const ChannelControl channelControl) = 0;

    /**
     * Releases the communication channel previously established with the card.
     *
     * @throw ReaderBrokenCommunicationException If the communication with the reader has failed.
     * @since 1.0
     */
    virtual void releaseChannel() = 0;
};

}
}
}
