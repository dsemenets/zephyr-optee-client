# SPDX-License-Identifier: Apache-2.0

add_library(OPTEE_SHELL INTERFACE)

zephyr_library()
zephyr_library_sources_ifdef(CONFIG_OPTEE_LIBTEEC src/teec_cmds.c)
zephyr_library_link_libraries(OPTEE_SHELL)
