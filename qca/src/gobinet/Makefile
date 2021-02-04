#!/usr/bin/make -f
# file: Makefile

# ====================================================================
# environment;
# --------------------------------------------------------------------

# ====================================================================
# package symbols;
# --------------------------------------------------------------------

ARCHIVE=$(shell basename "${CURDIR}")
PACKAGE=$(shell basename "${CURDIR}")
FOLDERS=GobiConnectionMgmt GobiSampleCM
EXCLUDE=--exclude=.git --exclude=*.[0-9][0-9][0-9]

# ====================================================================
# installation targets;
# --------------------------------------------------------------------

.PHONY: all compile compact scripts manuals install uninstall clean check ignore

all compile compact scripts manuals install uninstall clean check ignore:
	@for folder in ${FOLDERS}; do ${MAKE} -C $${folder} ${@} || exit 1; done

# ====================================================================
# archive targets;
# --------------------------------------------------------------------

.PHONY: archive restore

archive: clean
	tar ${EXCLUDE} -vzcf ../${ARCHIVE}.tar.gz  -C .. ${PACKAGE}
	tar ${EXCLUDE} -vzcf ~/boards/lte/${ARCHIVE}.tar.gz  -C .. ${PACKAGE}
restore:
	tar -vzxf ../${ARCHIVE}.tar.gz -C ..

