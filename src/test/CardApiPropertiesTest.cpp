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

#include <regex>

#include "gmock/gmock.h"
#include "gtest/gtest.h"

/* Calypsonet Terminal Card */
#include "CardApiProperties.h"

using namespace testing;

using namespace calypsonet::terminal::card;

TEST(CardApiPropertiesTest, versionIsCorrectlyWritten)
{
    const std::string& apiVersion = CardApiProperties::VERSION;
    const std::regex r("\\d+\\.\\d+");

    ASSERT_TRUE(std::regex_match(apiVersion, r));
}
