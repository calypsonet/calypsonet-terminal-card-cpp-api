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

namespace calypsonet {
namespace terminal {
namespace card {
namespace spi {

/**
 * Marker interface providing run-time type information about data defining the
 * <b>calypsonet::terminal::reader::selection::spi::SmartCard</b> resulting of the selection process
 * provided by the <b>Terminal Reader API</b>.
 *
 * <p>An adapter of this interface must also implement <b>SmartCard</b>.
 *
 * @since 1.0.0
 */
class SmartCardSpi {
public:
    /**
     * 
     */
    virtual ~SmartCardSpi() = default;
};

}
}
}
}
