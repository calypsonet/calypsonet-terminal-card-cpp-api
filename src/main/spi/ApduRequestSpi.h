/**************************************************************************************************
 * Copyright (c) 2021 Calypso Networks Association https://calypsonet.org/                        *
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

#include <cstdint>
#include <string>
#include <vector>

namespace calypsonet {
namespace terminal {
namespace card {
namespace spi {

/**
 * Data to build a single APDU command to be sent to a card.
 *
 * @see org.calypsonet.terminal.card.ApduResponseApi
 * @since 1.0.0
 */
class ApduRequestSpi {
public:
    /**
     * Gets the APDU bytes to be sent to the card.
     *
     * @return A array of at least 4 bytes.
     * @since 1.0.0
     */
    virtual const std::vector<uint8_t>& getApdu() const = 0;

    /**
     * Gets the list of status words that must be considered successful for the APDU.
     *
     * @return A set of integer values containing at least 9000h.
     * @since 1.0.0
     */
    virtual const std::vector<int>& getSuccessfulStatusWords() const = 0;

    /**
     * Gets the information about this APDU request (e.g. command name).
     *
     * <p>These information are intended to improve the logging.
     *
     * @return Null if no information has been defined.
     * @since 1.0.0
     */
    virtual const std::string& getInfo() const = 0;
};

}
}
}
}
