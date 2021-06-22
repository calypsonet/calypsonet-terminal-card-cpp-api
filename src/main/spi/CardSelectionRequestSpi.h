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
 * @since 1.0
 */
class CardSelectionRequestSpi {
public:
    /**
     * Gets the card selector.
     *
     * @return A not null reference.
     * @since 1.0
     */
    virtual const std::shared_ptr<CardSelectorSpi> getCardSelector() const = 0;

    /**
     * Gets the card request.
     *
     * @return Null if no card request has been defined.
     * @since 1.0
     */
    virtual const std::shared_ptr<CardRequestSpi> getCardRequest() const = 0;
};

}
}
}
}
