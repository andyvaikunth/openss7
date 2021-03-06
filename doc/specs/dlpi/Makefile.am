## vim: ft=automake comments=b\:#,b\:##,b\:#\! formatoptions+=tcqlor
## =============================================================================
## 
# @(#) File: doc/specs/dlpi/Makefile.am  Version: @VERSION@  Date: @PACKAGE_DATE@
##
## -----------------------------------------------------------------------------
##
## Copyright (c) 2008-2015  Monavacon Limited <http://www.monavacon.com/>
## Copyright (c) 2001-2008  OpenSS7 Corporation <http://www.openss7.com/>
## Copyright (c) 1997-2001  Brian F. G. Bidulock <bidulock@openss7.org>
##
## All Rights Reserved.
##
## This program is free software; you can redistribute it and/or modify it under
## the terms of the GNU Affero General Public License as published by the Free
## Software Foundation; version 3 of the License.
##
## This program is distributed in the hope that it will be useful, but WITHOUT
## ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
## FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
## details.
##
## You should have received a copy of the GNU Affero General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>, or
## write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA
## 02139, USA.
##
## -----------------------------------------------------------------------------
##
## U.S. GOVERNMENT RESTRICTED RIGHTS.  If you are licensing this Software on
## behalf of the U.S. Government ("Government"), the following provisions apply
## to you.  If the Software is supplied by the Department of Defense ("DoD"), it
## is classified as "Commercial Computer Software" under paragraph 252.227-7014
## of the DoD Supplement to the Federal Acquisition Regulations ("DFARS") (or any
## successor regulations) and the Government is acquiring only the license rights
## granted herein (the license rights customarily provided to non-Government
## users).  If the Software is supplied to any unit or agency of the Government
## other than DoD, it is classified as "Restricted Computer Software" and the
## Government's rights in the Software are defined in paragraph 52.227-19 of the
## Federal Acquisition Regulations ("FAR") (or any successor regulations) or, in
## the cases of NASA, in paragraph 18.52.227-86 of the NASA Supplement to the FAR
## (or any successor regulations).
##
## -----------------------------------------------------------------------------
##
## Commercial licensing and support of this software is available from OpenSS7
## Corporation at a fee.  See http://www.openss7.com/
##
## =============================================================================

include ../../../am/openss7.am

info_TEXINFOS		=

if DEVELOPMENT
## DEVELOPMENT

info_TEXINFOS		+= dlpi.texi

dlpi.h: $(top_srcdir)/src/include/sys/dlpi.h
	$(AM_V_GEN)cat $< | sed -e '1,/\*\//d;/doxygen/d;/#ident/d;/^\/\/\//d' | cat -s | expand > $@

CLEANFILES += dlpi.h

dlpi_TEXINFOS		= \
			  dlpi.h \
			  $(top_srcdir)/scripts/texi/macros.texi \
			  $(top_srcdir)/scripts/texi/versions.texi

if MAINTAINER_MODE
if AMDEP
dlpi_TEXINFOS		+= \
			  $(top_builddir)/scripts/texi/args.texi
endif
endif

EXTRA_info_TEXINFOS	= \
			  $(top_builddir)/scripts/texi/args.texi \
			  $(info_TEXINFOS) \
			  $(dlpi_TEXINFOS)

if PKG_BUILD_INDEP
## PKG_BUILD_INDEP

FIG_FIGS		= \
			dlpi_fig1.fig \
			dlpi_fig2.fig \
			dlpi_fig3.fig \
			dlpi_fig4.fig \
			dlpi_fig5.fig \
			dlpi_fig6.fig \
			dlpi_fig7.fig \
			dlpi_fig8.fig \
			dlpi_fig9.fig \
			dlpi_fi10.fig \
			dlpi_fi11.fig \
			dlpi_fi12.fig \
			dlpi_fi13.fig \
			dlpi_fi14.fig \
			dlpi_fi15.fig \
			dlpi_fi16.fig \
			dlpi_fi17.fig \
			dlpi_fi18.fig \
			dlpi_fi19.fig \
			dlpi_fi20.fig \
			dlpi_fi21.fig \
			dlpi_fi22.fig \
			dlpi_fi23.fig \
			dlpi_fi24.fig \
			dlpi_fi25.fig \
			dlpi_fi26.fig \
			dlpi_fi27.fig \
			dlpi_fi28.fig \
			dlpi_fi29.fig \
			dlpi_fi29b.fig \
			dlpi_fi30.fig \
			dlpi_fi31.fig \
			dlpi_fi32.fig \
			dlpi_fi33.fig \
			dlpi_fi34.fig \
			dlpi_fi35.fig

TBL_TBLS		= \
			dlpi_tab1.tbl \
			dlpi_tab2.tbl \
			dlpi_tab3.tbl \
			dlpi_tab4.tbl \
			dlpi_tab5.tbl \
			dlpi_tab6.tbl \
			dlpi_tab7.tbl \
			dlpi_tab8.tbl \
			dlpi_tab9.tbl \
			dlpi_ta10.tbl \
			dlpi_ta11.tbl \
			dlpi_ta12.tbl \
			dlpi_ta13.tbl \
			dlpi_ta14.tbl \
			dlpi_ta15.tbl \
			dlpi_ta16.tbl \
			dlpi_ta17.tbl \
			dlpi_ta18.tbl \
			dlpi_ta19.tbl

## PKG_BUILD_INDEP
endif

## DEVELOPMENT
endif

include ../../../am/info.am

## =============================================================================
## vim: ft=automake comments=b\:#,b\:##,b\:#\! formatoptions+=tcqlor
