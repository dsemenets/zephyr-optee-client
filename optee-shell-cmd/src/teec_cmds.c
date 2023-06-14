/*
 * Copyright (c) 2023 EPAM Systems
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <stdio.h>
#include <string.h>
#include <zephyr/sys/util.h>
#include <zephyr/shell/shell.h>
#include <tee_client_api.h>

static TEEC_Context ctx;

static int libteec_shell_vers(const struct shell *shell, size_t argc, char **argv)
{
    TEEC_Result res = TEEC_InitializeContext(NULL, &ctx);
    shell_print(shell, "Result: %d", res);
    return 0;
}

SHELL_STATIC_SUBCMD_SET_CREATE(
	subcmd_optee_libteec,
	SHELL_CMD_ARG(test, NULL,
		      " Test command\n",
		      libteec_shell_vers, 1, 0),
	SHELL_SUBCMD_SET_END);

SHELL_CMD_ARG_REGISTER(optee, &subcmd_optee_libteec, "OPTEE-client commands", NULL, 2, 0);
