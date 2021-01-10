//
// execution.hpp
// ~~~~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ASIO_EXECUTION_HPP
#define ASIO_EXECUTION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "asio_include_dir/asio/execution/allocator.hpp"
#include "asio_include_dir/asio/execution/any_executor.hpp"
#include "asio_include_dir/asio/execution/bad_executor.hpp"
#include "asio_include_dir/asio/execution/blocking.hpp"
#include "asio_include_dir/asio/execution/blocking_adaptation.hpp"
#include "asio_include_dir/asio/execution/bulk_execute.hpp"
#include "asio_include_dir/asio/execution/bulk_guarantee.hpp"
#include "asio_include_dir/asio/execution/connect.hpp"
#include "asio_include_dir/asio/execution/context.hpp"
#include "asio_include_dir/asio/execution/context_as.hpp"
#include "asio_include_dir/asio/execution/execute.hpp"
#include "asio_include_dir/asio/execution/executor.hpp"
#include "asio_include_dir/asio/execution/invocable_archetype.hpp"
#include "asio_include_dir/asio/execution/mapping.hpp"
#include "asio_include_dir/asio/execution/occupancy.hpp"
#include "asio_include_dir/asio/execution/operation_state.hpp"
#include "asio_include_dir/asio/execution/outstanding_work.hpp"
#include "asio_include_dir/asio/execution/prefer_only.hpp"
#include "asio_include_dir/asio/execution/receiver.hpp"
#include "asio_include_dir/asio/execution/receiver_invocation_error.hpp"
#include "asio_include_dir/asio/execution/relationship.hpp"
#include "asio_include_dir/asio/execution/schedule.hpp"
#include "asio_include_dir/asio/execution/scheduler.hpp"
#include "asio_include_dir/asio/execution/sender.hpp"
#include "asio_include_dir/asio/execution/set_done.hpp"
#include "asio_include_dir/asio/execution/set_error.hpp"
#include "asio_include_dir/asio/execution/set_value.hpp"
#include "asio_include_dir/asio/execution/start.hpp"
#include "asio_include_dir/asio/execution/submit.hpp"

#endif // ASIO_EXECUTION_HPP
