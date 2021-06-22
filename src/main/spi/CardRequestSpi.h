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
#include <vector>

/* Calypsonet Terminal Card */
#include "ApduRequestSpi.h"

namespace calypsonet {
namespace terminal {
namespace card {
namespace spi {

/**
 * Request grouping multiple APDUs to be executed consecutively.
 *
 * <p>Contains a list of {@link ApduRequestSpi} to be sent to a card and a flag indicating whether
 * to stop processing in case of an unexpected status word in response to one of the APDUs.
 *
 * @see calypsonet::terminal::card::ApduResponseApi
 * @since 1.0
 */
class CardRequestSpi {
public:
    /**
     * Gets the list of calypsonet::terminal::card::spi::ApduRequestSpi.
     *
     * @return A not empty list.
     * @since 1.0
     */
    virtual const std::vector<std::shared_ptr<ApduRequestSpi>> getApduRequests() const = 0;

    /**
     * Indicates if the processing of the requests must stop when an unexpected status word is
     * received.
     *
     * @return True if the process must stop at the first unsuccessful status word received.
     * @since 1.0
     */
    virtual bool stopOnUnsuccessfulStatusWord() = 0;
};

}
}
}
}
