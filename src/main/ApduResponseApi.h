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

#include <cstdint>
#include <vector>

namespace calypsonet {
namespace terminal {
namespace card {

/**
 * Data received in response to an APDU command.
 *
 * <p>Consists in a data part of variable length and a status word (SW1SW2).
 *
 * @see calypsonet::terminal::card::spi::ApduRequestSpi
 * @since 1.0
 */
class ApduResponseApi {
public:
    /**
     * Gets the raw data received from the card (including the status word).
     *
     * @return An array of at least 2 bytes.
     * @since 1.0
     */
    virtual const std::vector<uint8_t>& getApdu() const = 0;

    /**
     * Gets the data part of the response received from the card (excluding the status word).
     *
     * @return A not null byte array.
     * @since 1.0
     */
    virtual const std::vector<uint8_t> getDataOut() const = 0;

    /**
     * Gets the status word of the APDU as an int.
     *
     * @return An integer between 0000h and FFFFh.
     * @since 1.0
     */
    virtual int getStatusWord() const = 0;
};

}
}
}
