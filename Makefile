
DISTS := $(shell find . -maxdepth 1 -type d -print | grep -v "\./\.")


ACTIONS = build run

all: 
	@for DIST in $(DISTS) ; do \
	  VERSIONS=`find $$DIST -maxdepth 1 -type d -print` ; \
	    for VERSION in $$VERSIONS ; do \
	      for ACTION in $(ACTIONS) ; do \
	        if [ -x $$VERSION/$$ACTION ] ; then \
	          $(MAKE) -C $$VERSION/$$ACTION || exit 1; \
	       	fi \
	      done \
	    done \
	done

run: 
	@for DIST in $(DISTS) ; do \
	  VERSIONS=`find $$DIST -maxdepth 1 -type d -print` ; \
	    for VERSION in $$VERSIONS ; do \
	      if [ -x $$VERSION/run ] ; then \
	        $(MAKE) -C $$VERSION/run || exit 1; \
	      fi \
	    done \
	done

clean: 
	@for DIST in $(DISTS) ; do \
	  VERSIONS=`find $$DIST -maxdepth 1 -type d -print` ; \
	    for VERSION in $$VERSIONS ; do \
	      for ACTION in $(ACTIONS) ; do \
	        if [ -x $$VERSION/$$ACTION ] ; then \
	          $(MAKE) -C $$VERSION/$$ACTION clean || exit 1; \
	       	fi \
	      done \
	    done \
	done
