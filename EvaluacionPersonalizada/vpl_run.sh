#!/bin/sh
cat > vpl_execution <<'EEOOFF'
#!/bin/sh
echo ejecuta por ejemplo '"suma(2,3)"';
octave --no-window-system -q ;
EEOOFF
chmod +x vpl_execution