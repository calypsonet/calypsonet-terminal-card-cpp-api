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

#include <memory>
#include <ostream>

/* Calypsonet Terminal Card */
#include "CardRequestSpi.h"
#include "CardSelectorSpi.h"

namespace calypsonet {
namespace terminal {
namespace card {
namespace spi {

/**
 * Data provided as input to the selection process.
 *
 * <p>Embeds a card selector defining the target card profile and an optional card request to be
 * executed after the card selection when successful.
 *
 * @see calypsonet::terminal::card::CardSelectionResponseApi
 * @since 1.0.0
 */
class CardSelectionRequestSpi {
public:
    /**
     * Gets the card selector.
     *
     * @return A not null reference.
     * @since 1.0.0
     */
    virtual std::shared_ptr<CardSelectorSpi> getCardSelector() const = 0;

    /**
     * Gets the card request.
     *
     * @return Null if no card request has been defined.
     * @since 1.0.0
     */
    virtual std::shared_ptr<CardRequestSpi> getCardRequest() const = 0;

    /**
     *
     */
    friend std::ostream& operator<<(std::ostream& os,
                                    const std::shared_ptr<CardSelectionRequestSpi> csr)
    {
        (void)csr;

        os << "CARD_SELECTION_REQUEST_SPI: {"
           << "<TODO>"
           << "}";

        return os;
    }

    /**
     *
     */
    friend std::ostream& operator<<(
        std::ostream& os, const std::vector<std::shared_ptr<CardSelectionRequestSpi>>& csrs)
    {
        os << "CARD_SELECTION_REQUEST_SPIS: {";

        for (auto it = std::begin(csrs); it != std::end(csrs); ++it) {
            os << *it;
            if (it != csrs.end()) {
                os << ", ";
            }
        }

        os << "}";

        return os;
    }
};

}
}
}
}
