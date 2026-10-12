SSH_USER := ivmirand
SSH_PORT := 4242
HOST_ONLY_IP := 192.168.56.101
LOCAL_HOST := 127.0.0.1
LOCAL_PORT := 8443
REMOTE_PORT := 443
REMOTE_DIR := /home/ivmirand/inception
REMOTE_DATA := /home/ivmirand/data

SSH_VM := ssh -p $(SSH_PORT) $(SSH_USER)@$(LOCAL_HOST)
RSYNC_SSH := ssh -p $(SSH_PORT)

TUNNEL_SOCKET := /tmp/tunnel_socket

.PHONY: all clean fclean re ssh db tunnel secrets deepclean

all: secrets
	@echo "Uploading Inception repo to the virtual machine..."
	$(SSH_VM) 'mkdir -p $(REMOTE_DIR) $(REMOTE_DATA)/wordpress $(REMOTE_DATA)/mariadb'
	rsync -az --delete -e '$(RSYNC_SSH)' ./ $(SSH_USER)@$(LOCAL_HOST):$(REMOTE_DIR)/
	@echo "Building and starting Inception..."
	$(SSH_VM) 'cd $(REMOTE_DIR) && docker compose -f srcs/docker-compose.yml up -d --build'
	@echo "Connecting the Inception virtual machine..."
	$(SSH_VM)

clean:
	$(SSH_VM) 'cd $(REMOTE_DIR) && docker compose -f srcs/docker-compose.yml down'

fclean:
	$(SSH_VM) 'cd $(REMOTE_DIR) && docker compose -f srcs/docker-compose.yml down -v'
	$(SSH_VM) -t 'sudo rm -rf $(REMOTE_DIR) $(REMOTE_DATA)'

re: fclean all

ssh:
	$(SSH_VM)

tunnel:
	ssh -f -N -M \
		-S $(TUNNEL_SOCKET) \
		-o ExitOnForwardFailure=yes \
		-p $(SSH_PORT) \
		-L $(LOCAL_PORT):$(LOCAL_HOST):$(REMOTE_PORT) \
		$(SSH_USER)@$(HOST_ONLY_IP)

tunnel-stop:
	-ssh -S $(TUNNEL_SOCKET) -O exit -p $(SSH_PORT) $(SSH_USER)@$(HOST_ONLY_IP)
	rm -f $(TUNNEL_SOCKET)

db:
	@echo "Connecting to MariaDB inside the Inception VM..."
	@$(SSH_VM) -t "docker exec -it mariadb mariadb -u root -p"

secrets:
	@mkdir -p secrets
	@chmod 700 secrets
	@for f in db_password.txt db_root_password.txt wp_admin_password.txt wp_user_password.txt; do \
		if [ ! -s "secrets/$$f" ]; then \
			umask 077; \
			openssl rand -hex 32 > "secrets/$$f"; \
			echo "Generated secrets/$$f"; \
		fi; \
	done
	@chmod 600 secrets/*.txt

deepclean: fclean
	@echo "Pruning global Docker builder cache..."
	$(SSH_VM) 'docker builder prune -af'
