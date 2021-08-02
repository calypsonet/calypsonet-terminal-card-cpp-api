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

#include <memory>
#include <ostream>
#include <vector>

/* Calypsonet Terminal Card */
#include "ApduResponseApi.h"

namespace calypsonet {
namespace terminal {
namespace card {

/**
 * Group of multiple APDU responses.
 *
 * <p>Contains a list of calypsonet::terminal::card::ApduResponseApi received from the card in
 * response to a calypsonet::terminal::card::spi::CardRequestSpi and the associated execution
 * status.
 *
 * <p>The execution status includes the state of the logical channel after the operation and the
 * information saying whether a response is present for all APDUs in the
 * calypsonet::terminal::card::spi::CardRequestSpi.
 *
 * <p>Responses may be missing when this object is embedded in an
 * calypsonet::terminal::card::AbstractApduException, for example, if the card is removed during
 * processing or if an unsuccessful status word was received and processing was requested to be
 * stopped in this case (see
 * calypsonet::terminal::card::spi::CardRequestSpi::stopOnUnsuccessfulStatusWord()).
 *
 * @see calypsonet::terminal::card::spi::CardRequestSpi
 * @since 1.0
 */
class CardResponseApi {
public:
    /**
     * Gets a list of all responses received to the executed APDU requests.
     *
     * @return A not null list, empty if there is no response.
     * @since 1.0
     */
    virtual const std::vector<std::shared_ptr<ApduResponseApi>>& getApduResponses() const = 0;

    /**
     * Gets the state of the logical channel following the execution of the request.
     *
     * @return True if the logical channel is open.
     * @since 1.0
     */
    virtual bool isLogicalChannelOpen() const = 0;

    /**
     *
     */
    friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<CardResponseApi> cra)
    {
        os << "CARD_RESPONSE_API: {"
           << "IS_LOGICAL_CHANNEL_OPEN = " << cra->isLogicalChannelOpen() << ", "
           << cra->getApduResponses()
           << "}";

        return os;
    }
};

}
}
}
