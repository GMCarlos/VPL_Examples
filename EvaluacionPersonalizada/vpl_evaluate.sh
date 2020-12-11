#!/bin/sh
cat>vpl_execution <<'EEOOFF'
#!/bin/sh
octave --no-window-system -q --eval "evalua";
EEOOFF
chmod +x vpl_execution