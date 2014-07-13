/*
Copyright (c) 2014, Ronnie Sahlberg
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies, 
either expressed or implied, of the FreeBSD Project.
*/

/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "libnfs-zdr.h"
#include "libnfs-raw-nlm.h"

uint32_t
zdr_nlm_fh4 (ZDR *zdrs, nlm_fh4 *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_bytes (zdrs, (char **)&objp->data.data_val, (u_int *) &objp->data.data_len, ~0))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_nlm4_oh (ZDR *zdrs, nlm4_oh *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_string (zdrs, objp, ~0))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_nlm_cookie (ZDR *zdrs, nlm_cookie *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_bytes (zdrs, (char **)&objp->data.data_val, (u_int *) &objp->data.data_len, ~0))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_nlmstat4 (ZDR *zdrs, nlmstat4 *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_enum (zdrs, (enum_t *) objp))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_nlm4_holder (ZDR *zdrs, nlm4_holder *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_bool (zdrs, &objp->exclusive))
		 return FALSE;
	 if (!zdr_u_int (zdrs, &objp->svid))
		 return FALSE;
	 if (!zdr_nlm4_oh (zdrs, &objp->oh))
		 return FALSE;
	 if (!zdr_u_quad_t (zdrs, &objp->l_offset))
		 return FALSE;
	 if (!zdr_u_quad_t (zdrs, &objp->l_len))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_nlm4_lock (ZDR *zdrs, nlm4_lock *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_string (zdrs, &objp->caller_name, NLM_MAXNAME))
		 return FALSE;
	 if (!zdr_nlm_fh4 (zdrs, &objp->fh))
		 return FALSE;
	 if (!zdr_nlm4_oh (zdrs, &objp->oh))
		 return FALSE;
	 if (!zdr_u_int (zdrs, &objp->svid))
		 return FALSE;
	 if (!zdr_u_quad_t (zdrs, &objp->l_offset))
		 return FALSE;
	 if (!zdr_u_quad_t (zdrs, &objp->l_len))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_nlm4_share (ZDR *zdrs, nlm4_share *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_string (zdrs, &objp->caller_name, NLM_MAXNAME))
		 return FALSE;
	 if (!zdr_nlm_fh4 (zdrs, &objp->fh))
		 return FALSE;
	 if (!zdr_nlm4_oh (zdrs, &objp->oh))
		 return FALSE;
	 if (!zdr_u_int (zdrs, &objp->mode))
		 return FALSE;
	 if (!zdr_u_int (zdrs, &objp->access))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_nlm4_testres_denied (ZDR *zdrs, nlm4_testres_denied *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlm4_holder (zdrs, &objp->holder))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_nlm4_testreply (ZDR *zdrs, nlm4_testreply *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlmstat4 (zdrs, &objp->status))
		 return FALSE;
	switch (objp->status) {
	case NLM4_DENIED:
		 if (!zdr_nlm4_testres_denied (zdrs, &objp->nlm4_testreply_u.lock))
			 return FALSE;
		break;
	default:
		break;
	}
	return TRUE;
}

uint32_t
zdr_NLM4_TESTres (ZDR *zdrs, NLM4_TESTres *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlm4_testreply (zdrs, &objp->reply))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_NLM4_TESTargs (ZDR *zdrs, NLM4_TESTargs *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->exclusive))
		 return FALSE;
	 if (!zdr_nlm4_lock (zdrs, &objp->lock))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_NLM4_CANCres (ZDR *zdrs, NLM4_CANCres *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlmstat4 (zdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_NLM4_CANCargs (ZDR *zdrs, NLM4_CANCargs *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->block))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->exclusive))
		 return FALSE;
	 if (!zdr_nlm4_lock (zdrs, &objp->lock))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_NLM4_UNLOCKres (ZDR *zdrs, NLM4_UNLOCKres *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlmstat4 (zdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_NLM4_UNLOCKargs (ZDR *zdrs, NLM4_UNLOCKargs *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlm4_lock (zdrs, &objp->lock))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_NLM4_LOCKres (ZDR *zdrs, NLM4_LOCKres *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlmstat4 (zdrs, &objp->status))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_NLM4_LOCKargs (ZDR *zdrs, NLM4_LOCKargs *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->block))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->exclusive))
		 return FALSE;
	 if (!zdr_nlm4_lock (zdrs, &objp->lock))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->reclaim))
		 return FALSE;
	 if (!zdr_int (zdrs, &objp->state))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_NLM4_GRANTEDargs (ZDR *zdrs, NLM4_GRANTEDargs *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_bool (zdrs, &objp->exclusive))
		 return FALSE;
	 if (!zdr_nlm4_lock (zdrs, &objp->lock))
		 return FALSE;
	return TRUE;
}

uint32_t
zdr_NLM4_GRANTEDres (ZDR *zdrs, NLM4_GRANTEDres *objp)
{
	register int32_t *buf;
	buf = NULL;

	 if (!zdr_nlm_cookie (zdrs, &objp->cookie))
		 return FALSE;
	 if (!zdr_nlmstat4 (zdrs, &objp->status))
		 return FALSE;
	return TRUE;
}
