//
// ts/executor.hpp
// ~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ASIO_TS_EXECUTOR_HPP
#define ASIO_TS_EXECUTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
# pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

#include "asio_include_dir/asio/async_result.hpp"
#include "asio_include_dir/asio/associated_allocator.hpp"
#include "asio_include_dir/asio/execution_context.hpp"
#include "asio_include_dir/asio/is_executor.hpp"
#include "asio_include_dir/asio/associated_executor.hpp"
#include "asio_include_dir/asio/bind_executor.hpp"
#include "asio_include_dir/asio/executor_work_guard.hpp"
#include "asio_include_dir/asio/system_executor.hpp"
#include "asio_include_dir/asio/executor.hpp"
#include "asio_include_dir/asio/any_io_executor.hpp"
#include "asio_include_dir/asio/dispatch.hpp"
#include "asio_include_dir/asio/post.hpp"
#include "asio_include_dir/asio/defer.hpp"
#include "asio_include_dir/asio/strand.hpp"
#include "asio_include_dir/asio/packaged_task.hpp"
#include "asio_include_dir/asio/use_future.hpp"

#endif // ASIO_TS_EXECUTOR_HPP
