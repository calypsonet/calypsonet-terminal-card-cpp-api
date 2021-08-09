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
#include <string>

/* Calypsonet Terminal Card API */
#include "CardResponseApi.h"

/* Keyple Core Util */
#include "Exception.h"

namespace calypsonet {
namespace terminal {
namespace card {

using namespace keyple::core::util::cpp::exception;

/**
 * Generic exception carrying response data received from the card until a communication failure
 * occurs or an unexpected APDU status code is received.
 *
 * @since 1.0
 */
class AbstractApduException : public Exception {
public:
    /**
     * Builds a new exception embedding card response data.
     *
     * @param cardResponseApi The card responses received so far.
     * @param isCardResponseComplete True if the number responses equals the number of requests
     *        present in the original calypsonet::terminal::card::spi::CardRequestSpi.
     * @param message The message to identify the exception context.
     * @since 1.0
     */
    AbstractApduException(const std::shared_ptr<CardResponseApi> cardResponseApi,
                          const bool isCardResponseComplete,
                          const std::string& message)
    : Exception(message),
      mCardResponseApi(cardResponseApi),
      mIsCardResponseComplete(isCardResponseComplete) {}

    /**
     * Builds a new exception embedding card response data with the originating exception.
     *
     * @param cardResponseApi The card responses received so far.
     * @param isCardResponseComplete True if the number responses equals the number of requests
     *        present in the original calypsonet::terminal::card::spi::CardRequestSpi.
     * @param message Message to identify the exception context.
     * @param cause The cause
     * @since 1.0
     */
    AbstractApduException(const std::shared_ptr<CardResponseApi> cardResponseApi,
                          const bool isCardResponseComplete,
                          const std::string& message,
                          const std::shared_ptr<Exception> cause)
    : Exception(message, cause),
      mCardResponseApi(cardResponseApi),
      mIsCardResponseComplete(isCardResponseComplete) {}

    /**
     * Gets the response data received so far.
     *
     * @return A not null reference.
     * @since 1.0
     */
    virtual const std::shared_ptr<CardResponseApi> getCardResponse() const final
    {
        return mCardResponseApi;
    }

    /**
     * Indicates if all the responses expected from the corresponding
     * calypsonet::terminal::card::spi::CardRequestSpi have been received.
     *
     * @return True if all expected responses have been received.
     * @since 1.0
     */
    virtual bool isCardResponseComplete() const final
    {
        return mIsCardResponseComplete;
    }

private:
    /**
     *
     */
    const std::shared_ptr<CardResponseApi> mCardResponseApi;

    /**
     *
     */
    const bool mIsCardResponseComplete;
};

}
}
}
