FROM alpine as build-env
RUN apk add --no-cache build-base
WORKDIR /app
COPY . .
# Compile the binaries
RUN gcc -o helloworld hello.c
FROM alpine
COPY --from=build-env /app/helloworld /app/helloworld
WORKDIR /app
CMD ["/app/helloworld"]