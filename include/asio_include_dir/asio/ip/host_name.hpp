//
// ip/host_name.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ASIO_IP_HOST_NAME_HPP
#define ASIO_IP_HOST_NAME_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "asio_include_dir/asio/detail/config.hpp"
#include <string>
#include "asio_include_dir/asio/error_code.hpp"

#include "asio_include_dir/asio/detail/push_options.hpp"

namespace asio {
namespace ip {

/// Get the current host name.
ASIO_DECL std::string host_name();

/// Get the current host name.
ASIO_DECL std::string host_name(asio::error_code& ec);

} // namespace ip
} // namespace asio

#include "asio_include_dir/asio/detail/pop_options.hpp"

#if defined(ASIO_HEADER_ONLY)
# include "asio_include_dir/asio/ip/impl/host_name.ipp"
#endif // defined(ASIO_HEADER_ONLY)

#endif // ASIO_IP_HOST_NAME_HPP
