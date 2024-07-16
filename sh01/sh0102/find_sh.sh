find . -name "*.sh" -print | awk sub'("./","")' | sed 's/\.sh//'
