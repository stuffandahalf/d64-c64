/*
 * SPDX-License-Identifier: BSD-3-Clause
 * 
 * Copyright (c) 2021 Gregory Norton
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above
 *   copyright notice, this list of conditions and the following disclaimer
 *   in the documentation and/or other materials provided with the
 *   distribution.
 * * Neither the name of the  nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */


#include <stdio.h>
#include <unistd.h>

const char *VERSION = "0.1";

int configure(int argc, char **argv);

int main(int argc, char **argv)
{
	if (configure(argc, argv)) {
		return 1;
	}
	
	return 0;
}

void help(char *name)
{
	fprintf(stderr, "Usage: %s [-h|-v] [-b BAUD]\n", name);
}

void version(char *name)
{
	fprintf(stderr, "%s %s\n", name, VERSION);
	fprintf(stderr, "Copyright (c) 2021 Gregory Norton\n");
	/*fprintf(stderr, "THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND "
		"CONTRIBUTORS \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, "
		"INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF "
		"MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. "
		"IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR "
		"ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR "
		"CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF "
		"SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR "
		"BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, "
		"WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE "
		"OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, "
		"EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n");*/
}

int configure(int argc, char **argv)
{
	int c;
	
	while ((c = getopt(argc, argv, "hvb")) != -1) {
		switch (c) {
		case 'h':
			help(argv[0]);
			return 1;
		case 'v':
			version(argv[0]);
			return 1;
		case 'b':
			break;
		case '?':
		default:
			return 1;
		}
	}
	
	return 0;
}
