//
// impl/src.hpp
// ~~~~~~~~~~~~
//
// Copyright (c) 2003-2020 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef ASIO_IMPL_SRC_HPP
#define ASIO_IMPL_SRC_HPP

#define ASIO_SOURCE

#include "asio_include_dir/asio/detail/config.hpp"

#if defined(ASIO_HEADER_ONLY)
# error Do not compile Asio library source with ASIO_HEADER_ONLY defined
#endif

#include "asio_include_dir/asio/impl/error.ipp"
#include "asio_include_dir/asio/impl/error_code.ipp"
#include "asio_include_dir/asio/impl/execution_context.ipp"
#include "asio_include_dir/asio/impl/executor.ipp"
#include "asio_include_dir/asio/impl/handler_alloc_hook.ipp"
#include "asio_include_dir/asio/impl/io_context.ipp"
#include "asio_include_dir/asio/impl/multiple_exceptions.ipp"
#include "asio_include_dir/asio/impl/serial_port_base.ipp"
#include "asio_include_dir/asio/impl/system_context.ipp"
#include "asio_include_dir/asio/impl/thread_pool.ipp"
#include "asio_include_dir/asio/detail/impl/buffer_sequence_adapter.ipp"
#include "asio_include_dir/asio/detail/impl/descriptor_ops.ipp"
#include "asio_include_dir/asio/detail/impl/dev_poll_reactor.ipp"
#include "asio_include_dir/asio/detail/impl/epoll_reactor.ipp"
#include "asio_include_dir/asio/detail/impl/eventfd_select_interrupter.ipp"
#include "asio_include_dir/asio/detail/impl/handler_tracking.ipp"
#include "asio_include_dir/asio/detail/impl/kqueue_reactor.ipp"
#include "asio_include_dir/asio/detail/impl/null_event.ipp"
#include "asio_include_dir/asio/detail/impl/pipe_select_interrupter.ipp"
#include "asio_include_dir/asio/detail/impl/posix_event.ipp"
#include "asio_include_dir/asio/detail/impl/posix_mutex.ipp"
#include "asio_include_dir/asio/detail/impl/posix_thread.ipp"
#include "asio_include_dir/asio/detail/impl/posix_tss_ptr.ipp"
#include "asio_include_dir/asio/detail/impl/reactive_descriptor_service.ipp"
#include "asio_include_dir/asio/detail/impl/reactive_serial_port_service.ipp"
#include "asio_include_dir/asio/detail/impl/reactive_socket_service_base.ipp"
#include "asio_include_dir/asio/detail/impl/resolver_service_base.ipp"
#include "asio_include_dir/asio/detail/impl/scheduler.ipp"
#include "asio_include_dir/asio/detail/impl/select_reactor.ipp"
#include "asio_include_dir/asio/detail/impl/service_registry.ipp"
#include "asio_include_dir/asio/detail/impl/signal_set_service.ipp"
#include "asio_include_dir/asio/detail/impl/socket_ops.ipp"
#include "asio_include_dir/asio/detail/impl/socket_select_interrupter.ipp"
#include "asio_include_dir/asio/detail/impl/strand_executor_service.ipp"
#include "asio_include_dir/asio/detail/impl/strand_service.ipp"
#include "asio_include_dir/asio/detail/impl/throw_error.ipp"
#include "asio_include_dir/asio/detail/impl/timer_queue_ptime.ipp"
#include "asio_include_dir/asio/detail/impl/timer_queue_set.ipp"
#include "asio_include_dir/asio/detail/impl/win_iocp_handle_service.ipp"
#include "asio_include_dir/asio/detail/impl/win_iocp_io_context.ipp"
#include "asio_include_dir/asio/detail/impl/win_iocp_serial_port_service.ipp"
#include "asio_include_dir/asio/detail/impl/win_iocp_socket_service_base.ipp"
#include "asio_include_dir/asio/detail/impl/win_event.ipp"
#include "asio_include_dir/asio/detail/impl/win_mutex.ipp"
#include "asio_include_dir/asio/detail/impl/win_object_handle_service.ipp"
#include "asio_include_dir/asio/detail/impl/win_static_mutex.ipp"
#include "asio_include_dir/asio/detail/impl/win_thread.ipp"
#include "asio_include_dir/asio/detail/impl/win_tss_ptr.ipp"
#include "asio_include_dir/asio/detail/impl/winrt_ssocket_service_base.ipp"
#include "asio_include_dir/asio/detail/impl/winrt_timer_scheduler.ipp"
#include "asio_include_dir/asio/detail/impl/winsock_init.ipp"
#include "asio_include_dir/asio/execution/impl/bad_executor.ipp"
#include "asio_include_dir/asio/execution/impl/receiver_invocation_error.ipp"
#include "asio_include_dir/asio/generic/detail/impl/endpoint.ipp"
#include "asio_include_dir/asio/ip/impl/address.ipp"
#include "asio_include_dir/asio/ip/impl/address_v4.ipp"
#include "asio_include_dir/asio/ip/impl/address_v6.ipp"
#include "asio_include_dir/asio/ip/impl/host_name.ipp"
#include "asio_include_dir/asio/ip/impl/network_v4.ipp"
#include "asio_include_dir/asio/ip/impl/network_v6.ipp"
#include "asio_include_dir/asio/ip/detail/impl/endpoint.ipp"
#include "asio_include_dir/asio/local/detail/impl/endpoint.ipp"

#endif // ASIO_IMPL_SRC_HPP
