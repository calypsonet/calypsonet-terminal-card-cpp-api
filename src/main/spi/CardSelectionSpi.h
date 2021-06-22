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
#include "CardSelectionRequestSpi.h"
#include "CardSelectionResponseApi.h"
#include "SmartCardSpi.h"

namespace calypsonet {
namespace terminal {
namespace card {
namespace spi {

/**
 * Extension of the card selection manager for a specific card extension.
 *
 * <p>Provides the calypsonet::terminal::card::spi::CardSelectionRequestSpi and interprets the
 * result to provide a calypsonet::terminal::card::spi::SmartCardSpi.
 *
 * <p>Backside of the <b>calypsonet::terminal::reader::selection::spi::CardSelection</b> interface
 * present in the <b>Terminal Reader API</b>.
 *
 * <p>An adapter of this interface must also implement <b>CardSelection</b>.
 *
 * @since 1.0
 */
class CardSelectionSpi {
public:
    /**
     * Gets the card selection request containing the selection data prepared for this selection.
     *
     * @return A not null reference.
     * @since 1.0
     */
    virtual const std::shared_ptr<CardSelectionRequestSpi> getCardSelectionRequest() const = 0;

    /**
     * Analyzes the response received from the card during the selection process and creates a
     * calypsonet::terminal::card::spi::SmartCardSpi.
     *
     * @param cardSelectionResponseApi The card selection response.
     * @return A not null reference.
     * @throw ParseException If the card selection response parsing failed.
     * @since 1.0
     */
    virtual const std::shared_ptr<SmartCardSpi> parse(
        const std::shared_ptr<CardSelectionResponseApi> cardSelectionResponseApi) const = 0;
};

}
}
}
}
