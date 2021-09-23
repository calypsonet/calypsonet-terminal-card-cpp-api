/**************************************************************************************************
 * Copyright (c) 2021 Calypso Networks Association https://calypsonet.org/                        *                                                               *
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

#include <ostream>
#include <memory>

/* Calypsonet Terminal Card */
#include "ApduResponseApi.h"
#include "CardResponseApi.h"

namespace calypsonet {
namespace terminal {
namespace card {

/**
 * Data from the start-up phase with the card: selection data and any additional responses.
 *
 * <p>Includes the status of the selection itself and the responses to any commands that may have
 * been executed afterwards.
 *
 * @see org::calypsonet.terminal.card.spi.CardSelectionRequestSpi
 * @since 1.0
 */
class CardSelectionResponseApi {
public:
    /**
     * Gets the card's power-on data.
     *
     * <p>The power-on data is defined as the data retrieved by the reader when the card is
     * inserted.
     *
     * <p>In the case of a contact reader, this is the Answer To Reset data (ATR) defined by
     * ISO7816.
     *
     * <p>In the case of a contactless reader, the reader decides what this data is.<br>
     * Some contactless readers provide a virtual ATR (partially standardized by the PC/SC
     * standard), but other devices can have their own definition, including for example elements
     * from the anti-collision stage of the ISO14443 protocol (ATQA, ATQB, ATS, SAK, etc) or any
     * proprietary definitions.
     *
     * <p>These data being variable from one reader to another, they are defined here in string
     * format which can be either a hexadecimal string or any other relevant information.
     *
     * @return Null if no power-on data is available.
     * @since 1.0
     */
    virtual const std::string& getPowerOnData() const = 0;

    /**
     * Gets the calypsonet::terminal::card::ApduResponseApi received from the card in response to
     * the <b>Select Application</b> command.
     *
     * @return Null if no Select Application command was performed.
     * @since 1.0
     */
    virtual const std::shared_ptr<ApduResponseApi> getSelectApplicationResponse() const = 0;

    /**
     * Gives the selection process status.
     *
     * @return True if the card inserted matches the selection filters.
     * @since 1.0
     */
    virtual bool hasMatched() const = 0;

    /**
     * Gets the responses of the card to the requests present in the
     * calypsonet::terminal::card::spi::CardRequestSpi from the
     * calypsonet::terminal::card::spi::CardSelectionRequestSpi.
     *
     * @return Null if no requests have been set.
     * @since 1.0
     */
    virtual const std::shared_ptr<CardResponseApi> getCardResponse() const = 0;

    /**
     *
     */
    friend std::ostream& operator<<(std::ostream& os,
                                    const std::shared_ptr<CardSelectionResponseApi> csr)
    {
        os << "CARD_SELECTION_RESPONSE_API: {"
           << "HAS_MATCHED: " << csr->hasMatched()
           << "<TODO>"
           << "}";

        return os;
    }

    /**
     *
     */
    friend std::ostream& operator<<(
        std::ostream& os, const std::vector<std::shared_ptr<CardSelectionResponseApi>>& csrs)
    {
        os << "CARD_SELECTION_RESPONSE_APIS: {";

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
