while TRUE; do leaks smortier.filler | grep Process  | cut -f 3 | grep leaks | grep total; done
