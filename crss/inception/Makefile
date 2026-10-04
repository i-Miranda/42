# Variable con el comando SSH para no repetir código
SSH_USER = ivmirand
SSH_HOST = 127.0.0.1
SSH_PORT = 4242

SSH_VM = ssh $(SSH_USER)@$(SSH_HOST) -p $(SSH_PORT)

# ... tus otras reglas como all, clean, re ...

vm:
	@echo "Conecting the Inception virtual machine..."
	$(SSH_VM)

db:
	@echo "Connecting to MariaDB inside the Inception VM..."
	@$(SSH_VM) -t "docker exec -it mariadb mariadb -u root -p"

