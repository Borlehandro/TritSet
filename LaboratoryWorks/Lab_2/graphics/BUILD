cc_library (
    name = "window",
    srcs = ["window.cpp",],
    hdrs = ["window.h",],
    deps = ["@SDL2//:SDL2",],
    visibility = ["//visibility:public"]
)

cc_library (
    name = "visualizer",
    srcs = ["visualizer.cpp",],
    hdrs = ["visualizer.h","commands.h",],
    deps = ["@SDL2//:SDL2", ":window"],
    visibility = ["//visibility:public"]
)