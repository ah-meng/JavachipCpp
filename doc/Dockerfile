FROM jetbrains/writerside-builder:242.21870 as builder
LABEL authors="lch"

ARG INSTANCE=doc/d

RUN mkdir /opt/sources

WORKDIR /opt/sources

ADD . ./doc

RUN export DISPLAY=:99 && \
    Xvfb :99 & \
    /opt/builder/bin/idea.sh helpbuilderinspect --source-dir /opt/sources --product $INSTANCE --runner other --output-dir /opt/wrs-output/

WORKDIR /opt/wrs-output

RUN unzip -O UTF-8 webHelpD2-all.zip -d /opt/wrs-output/unzipped-artifact

FROM httpd:2.4 as http-server

COPY --from=builder /opt/wrs-output/unzipped-artifact/ /usr/local/apache2/htdocs/