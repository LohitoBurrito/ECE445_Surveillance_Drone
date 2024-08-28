import socket

def main():
    # Define the server address and port
    server_address = ('127.0.0.1', 5001)

    # Create a TCP/IP socket
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as sock:
        # Connect to the server
        print(f"Connecting to {server_address[0]}:{server_address[1]}")
        sock.connect(server_address)

        try:
            while True:
                # Receive data from the server
                data = sock.recv(1024)
                if not data:
                    break  # Connection closed by the server
                print(f"Received command: {data.decode()}")

        except KeyboardInterrupt:
            print("Client terminated by user.")

if __name__ == "__main__":
    main()
