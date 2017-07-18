FROM centos:centos7
MAINTAINER Hans Zandbelt <hans.zandbelt@zmartzone.eu>

# CentOS Linux release 7.0.1406 (Core)

RUN rpm --import http://dl.fedoraproject.org/pub/epel/RPM-GPG-KEY-EPEL-7
RUN rpm -ihv http://dl.fedoraproject.org/pub/epel/7/x86_64/e/epel-release-7-10.noarch.rpm

RUN yum update -y
