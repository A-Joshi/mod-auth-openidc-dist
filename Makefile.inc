VERSION_DIR := $(shell dirname `pwd`)
VERSION     := $(shell basename $(VERSION_DIR))

DIST_DIR    := $(shell dirname $(VERSION_DIR))
DIST        := $(shell basename $(DIST_DIR))

BUILD_TAG   := mod_auth_openidc_build/$(DIST)-$(VERSION)
RUN_TAG     := mod_auth_openidc_run/$(DIST)-$(VERSION)

build:
	docker build -t $(BUILD_TAG) .

build-nocache:
	docker build --no-cache=true -t $(BUILD_TAG) .

rpm-copy: build
	docker run --rm -v $$PWD:/shared:rw -it $(BUILD_TAG) /bin/bash -c "cp /opt/rpmbuild/rpm/RPMS/x86_64/*.rpm /shared"

deb-copy: build
	docker run --rm -v $$PWD:/shared:rw -it $(BUILD_TAG) /bin/bash -c "cp /root/*.deb /shared"

rpm-upload: rpm-copy
	echo "scp *.rpm zandbelt@mod-auth-openidc.org:/var/www/mod-auth-openidc.org/download"

deb-upload: deb-copy
	echo "scp *.deb zandbelt@mod-auth-openidc.org:/var/www/mod-auth-openidc.org/download"

rpm-clean:
	rm -f *.rpm

deb-clean:
	rm -f *.deb *.changes *.dsc

run:
	docker build -t $(RUN_TAG) .

run-nocache:
	docker build --no-cache=true -t $(RUN_TAG) .
	
