/*
  ***** BEGIN LICENSE BLOCK *****
 
  Copyright (C) 2001-2017 Olof Hagsand

  This file is part of CLIgen.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  Alternatively, the contents of this file may be used under the terms of
  the GNU General Public License Version 2 or later (the "GPL"),
  in which case the provisions of the GPL are applicable instead
  of those above. If you wish to allow use of your version of this file only
  under the terms of the GPL, and not to allow others to
  use your version of this file under the terms of Apache License version 2, indicate
  your decision by deleting the provisions above and replace them with the 
  notice and other provisions required by the GPL. If you do not delete
  the provisions above, a recipient may use your version of this file under
  the terms of any one of the Apache License version 2 or the GPL.

  ***** END LICENSE BLOCK *****

*/

#ifndef _CLIGEN_SYNTAX_H_
#define _CLIGEN_SYNTAX_H_

/*
 * Types
 */
typedef void *(str2fn_mapper)(char *str, void *arg, char **err);

/*
 * Prototypes
 */
int
cligen_parse_str(cligen_handle  h,
		 char          *str,
		 char          *name, 
		 parse_tree    *pt,
		 cvec          *globals);
int
cligen_parse_file(cligen_handle h,
		  FILE         *f,
		  char         *name, 
		  parse_tree   *obsolete,
		  cvec         *globals);

int cligen_parse_line(cligen_handle h,
               int           linenum,
	       cg_obj       *co_top, 
	       char         *filename, 
	       char         *string,
	       char         *callback_str,
	       cg_fnstype_t *callback,
	       cg_var       *arg,
	       int           hide);

int cligen_str2fn(parse_tree pt, 
		  str2fn_mapper *str2fn1, void *fnarg1, 
		  str2fn_mapper *str2fn2, void *fnarg2);
int cligen_callback_str2fn(parse_tree, cg_str2fn_t *str2fn, void *fnarg);
int cligen_parse_debug(int d); 

#endif /* _CLIGEN_SYNTAX_H_ */

