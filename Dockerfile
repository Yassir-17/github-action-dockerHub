# Stage 1: Build the application
FROM alpine as build-env
RUN apk add --no-cache build-base
WORKDIR /app
COPY . .
# Compile the binaries
RUN gcc -o web_server web_server.c

# Stage 2: Create the final image
FROM alpine
# Install necessary packages for running the server (like libc)
RUN apk add --no-cache libc6-compat

# Copy the compiled binary from the build stage
COPY --from=build-env /app/web_server /app/web_server

# Expose port 8080 for the web server
EXPOSE 8080

WORKDIR /app
# Run the web server
CMD ["/app/web_server"]

