cat /etc/passwd | grep _ | cut -d ":" -f1 | sed -n 'n;p' | rev | sort -r | tr '\n' ', '
