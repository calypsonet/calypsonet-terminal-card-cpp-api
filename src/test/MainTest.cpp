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

#include "gtest/gtest.h"

/* Util */
#include "Logger.h"

using namespace testing;

using namespace keyple::core::util::cpp;

int main(int argc, char **argv)
{
    /* Initialize GTest */
    ::testing::InitGoogleTest(&argc, argv);

    Logger::setLoggerLevel(Logger::Level::logError);

    /* Run */
    return RUN_ALL_TESTS();
}