# Variable con el comando SSH para no repetir código
SSH_USER := ivmirand
SSH_HOST := 127.0.0.1
SSH_PORT := 4242
REMOTE_DIR := /home/ivmirand/inception
REMOTE_DATA := /home/ivmirand/data

SSH_VM := ssh -p $(SSH_PORT) $(SSH_USER)@$(SSH_HOST)
RSYNC_SSH := ssh -p $(SSH_PORT)

.PHONY: all clean fclean db

# ... tus otras reglas como all, clean, re ...
all:
	@echo "Uploading Inception repo to the virtual machine..."
	$(SSH_VM) 'mkdir -p $(REMOTE_DIR) $(REMOTE_DATA)/wordpress $(REMOTE_DATA)/mariab'
	rsync -az --delete -e '$(RSYNC_SSH)' ./  $(SSH_USER)@$(SSH_HOST):$(REMOTE_DIR)/
	@echo "Building and starting Inception..."
	$(SSH_VM) 'cd $(REMOTE_DIR) && docker compose -f srcs/docker-compose.yml up -d --build'
	@echo "Conecting the Inception virtual machine..."
	$(SSH_VM)

clean:
	$(SSH_VM) 'cd $(REMOTE_DIR) && docker compose down'

fclean:
	$(SSH_VM) 'rm -rf $(REMOTE_DIR) $(REMOTE_DATA)'

db:
	@echo "Connecting to MariaDB inside the Inception VM..."
	@$(SSH_VM) -t "docker exec -it mariadb mariadb -u root -p"

