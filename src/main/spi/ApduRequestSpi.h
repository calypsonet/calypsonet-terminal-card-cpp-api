/**************************************************************************************************
 * Copyright (c) 2022 Calypso Networks Association https://calypsonet.org/                        *
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
#include <memory>
#include <ostream>
#include <string>
#include <vector>

/* Keyple Core Util */
#include "KeypleStd.h"

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
    virtual std::vector<uint8_t>& getApdu() = 0;

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

    /**
     *
     */
    friend std::ostream& operator<<(std::ostream& os, ApduRequestSpi& ars)
    {
        os << "APDU_REQUEST_SPI: {"
           << "APDU: " << ars.getApdu() << ", "
           << "SUCCESSFUL_STATUS_WORDS: " << ars.getSuccessfulStatusWords() << ", "
           << "INFO: " << ars.getInfo()
           << "}";

        return os;
    }

    /**
     *
     */
    friend std::ostream& operator<<(std::ostream& os, const std::shared_ptr<ApduRequestSpi> ars)
    {
        if (ars == nullptr) {
            os << "APDU_REQUEST_SPI: null";
        } else {
            os << *ars.get();
        }

        return os;
    }

    /**
     *
     */
    friend std::ostream& operator<<(std::ostream& os,
                                    const std::vector<std::shared_ptr<ApduRequestSpi>>& ars)
    {
        os << "APDU_REQUEST_SPIS: {";

        for (auto it = ars.begin(); it != ars.end(); it++) {
            if (it != ars.begin()) {
                os << ", ";
            }
            os << *it;
        }

        os << "}";

        return os;
    }
};

}
}
}
}
