CMP = gcc
EVM = -std=c99
SRC = *.c
OUT = single_cycle.out
CHK = diff
DEL = del

BIN  = *.bin
SNAP = snapshot.rpt
ERR  = error_dump.rpt

CASE 	= func
SMPPATH = ..\open_testcase\func

all: $(SRC)
	$(CMP) $(SRC) -o $(OUT) $(EVM)
	$(OUT)
check: $(SNAP) $(ERR)
	$(CHK) $(SNAP) $(SMPPATH)
	$(CHK) $(ERR) $(SMPPATH)
clean: $(BIN) $(SNAP) $(ERR)
	$(DEL) $(BIN) $(SNAP) $(ERR)