licenses(["notice"])  # Apache 2

load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_test",
    "envoy_package",
)

envoy_package()

envoy_cc_test(
    name = "manager_impl_test",
    srcs = ["manager_impl_test.cc"],
    deps = [
        "//source/common/singleton:manager_impl_lib",
        "//test/test_common:utility_lib",
    ],
)

envoy_cc_test(
    name = "threadsafe_singleton_test",
    srcs = ["threadsafe_singleton_test.cc"],
    deps = [
        "//source/common/common:thread_lib",
        "//source/common/singleton:threadsafe_singleton",
        "//test/test_common:threadsafe_singleton_injector_lib",
    ],
)
