import java.util.*;
import java.io.*;
import java.lang.*;

class Points {
	Points() {}
	int xCord[];
	int yCord[];
}

class BoardClass {
	public static int boardLength = 20;
	public char board[][] = new char[BoardClass.boardLength][BoardClass.boardLength];
}

class Version extends Points {
	public int versionNo = 1;

	Version() {
	}

	Version(int versionNo) {
		this.versionNo = versionNo;
	}

	public void changeVersion(int versionNo) {
		this.versionNo = versionNo;
	}

	public void changeVersionAnticlock(int versionNo) {
		this.versionNo = versionNo;
	}

	public void changeVersionClock(int versionNo) {
		this.versionNo = versionNo;
	}

	public boolean checkDown(char board[][]) {
		return false;
	}

	public boolean checkLeft(char board[][]) {
		return false;
	}

	public boolean checkRight(char board[][]) {
		return false;
	}

	public int getVersion() {
		return versionNo;
	}
}

class Line extends Version {
	public int boardLength = 20;

	Line() {
		Random r = new Random();
		int ranNo = r.nextInt(((boardLength - 5) - 5) + 1) + 5;
		xCord = new int[] { 4, 5, 6, 7 };
		yCord = new int[] { ranNo, ranNo, ranNo, ranNo };
	}

	public boolean checkDown(char board[][]) {
		if (versionNo == 1 && (board[xCord[3] + 1][yCord[3]] == '#')) {
			return true;
		} else if (versionNo == 2 && (board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[1] + 1][yCord[1]] == '#'
				|| board[xCord[2] + 1][yCord[2]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')) {
			return true;
		}
		return false;
	}

	public void changeVersionAnticlock(int versionNo) {
		super.changeVersion(versionNo);

		if (versionNo == 1) {
			for (int i = 0; i < xCord.length; i++) {
				xCord[i] = xCord[0] + i;
				yCord[i] = yCord[0];
			}
		} else if (versionNo == 2) {
			for (int i = 0; i < xCord.length; i++) {
				xCord[i] = xCord[0];
				yCord[i] = yCord[0] + i;
			}
		} else if (versionNo == 3) {
			for (int i = 0; i < xCord.length; i++) {
				xCord[i] = xCord[i] - i;
				yCord[i] = yCord[0];
			}
		} else if (versionNo == 4) {
			for (int i = 0; i < xCord.length; i++) {
				xCord[i] = xCord[0];
				yCord[i] = yCord[0] - i;
			}
		}
	}

	public boolean checkLeft(char board[][]) {
		if (versionNo == 1 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#'
				|| board[xCord[2]][yCord[2] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		} else if (versionNo == 2 && board[xCord[0]][yCord[0] - 1] == '#') {
			return true;
		}
		return false;
	}

	public boolean checkRight(char board[][]) {
		if (versionNo == 1 && (board[xCord[0]][yCord[0] + 1] == '#' || board[xCord[1]][yCord[1] + 1] == '#'
				|| board[xCord[2]][yCord[2] + 1] == '#' || board[xCord[3]][yCord[3] + 1] == '#')) {
			return true;
		} else if (versionNo == 2 && board[xCord[3]][yCord[3] - 1] == '#') {
			return true;
		}
		return false;
	}

	public void changeVersionClock(int versionNo) {
		super.changeVersion(versionNo);
		if (versionNo == 1) {
			for (int i = 0; i < xCord.length; i++) {
				xCord[i] = xCord[0] + i;
				yCord[i] = yCord[0];
			}
		} else if (versionNo == 2) {
			for (int i = 0; i < xCord.length; i++) {
				xCord[i] = xCord[0];
				yCord[i] = yCord[0] + i;
			}
		} else if (versionNo == 3) {
			for (int i = 0; i < xCord.length; i++) {
				xCord[i] = xCord[0] - i;
				yCord[i] = yCord[0];
			}
		} else if (versionNo == 4) {
			for (int i = 0; i < xCord.length; i++) {
				xCord[i] = xCord[0];
				yCord[i] = yCord[0] - i;
			}
		}
	}

	public void changeDirection() {
		for (int i = 0; i < 4; i++) {
			if (yCord[3] != (boardLength - 2)) {
				yCord[i] = yCord[i] + 1;
				xCord[i] = xCord[i] + 1;
			} else if (yCord[0] != (boardLength - 3))
				break;
			else
				break;
		}
	}
}

class Square extends Version {
	public static int boardLength = 20;

	Square() {
		Random r = new Random();
		int ranNo = r.nextInt(((boardLength - 5) - 5) + 1) + 5;
		xCord = new int[] { 1, 1, 2, 2 };
		yCord = new int[] { ranNo, ranNo + 1, ranNo, ranNo + 1 };
	}

	public boolean checkDown(char board[][]) {
		if (board[xCord[2] + 1][yCord[2]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')
			return true;
		return false;
	}

	public boolean checkLeft(char board[][]) {
		if (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#')
			return true;
		return false;
	}

	public boolean checkRight(char board[][]) {
		if (board[xCord[1]][yCord[1] + 1] == '#' || board[xCord[3]][yCord[3] + 1] == '#')
			return true;
		return false;
	}

	public void moveAntiClockWise(int versionNo) {
		super.changeVersion(versionNo);
	}

	public void moveClockWise(int versionNo) {
		super.changeVersion(versionNo);
	}
}

class TShape extends Version {
	public static int boardLength = 20;

	TShape() {
		Random r = new Random();
		int ranNo = r.nextInt(((boardLength - 5) - 5) + 1) + 5;
		xCord = new int[] { 1, 1, 1, 2 };
		yCord = new int[] { ranNo, ranNo + 1, ranNo + 2, ranNo + 1 };
	}

	public boolean checkDown(char board[][]) {
		if (versionNo == 1 && (board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[2] + 1][yCord[2]] == '#'
				|| board[xCord[3] + 1][yCord[3]] == '#')) {
			return true;
		} else if (versionNo == 2 && (board[xCord[2] + 1][yCord[2]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')) {
			return true;
		} else if (versionNo == 3 && (board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[1] + 1][yCord[1]] == '#'
				|| board[xCord[2] + 1][yCord[2]] == '#')) {
			return true;
		} else if (versionNo == 4 && (board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')) {
			return true;
		}
		return false;
	}

	public boolean checkLeft(char board[][]) {
		if (versionNo == 1 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		} else if (versionNo == 2 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#'
				|| board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		} else if (versionNo == 3 && (board[xCord[2]][yCord[2] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		} else if (versionNo == 4 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#'
				|| board[xCord[2]][yCord[2] - 1] == '#')) {
			return true;
		}
		return false;
	}

	public boolean checkRight(char board[][]) {
		if (versionNo == 1 && (board[xCord[2]][yCord[2] + 1] == '#' || board[xCord[3]][yCord[3] + 1] == '#')) {
			return true;
		} else if (versionNo == 2 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#'
				|| board[xCord[2]][yCord[2] - 1] == '#')) {
			return true;
		} else if (versionNo == 3 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		} else if (versionNo == 4 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#'
				|| board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		}
		return false;
	}

	public void changeVersionAnticlock(int versionNo) {
		super.changeVersion(versionNo);
		if (versionNo == 1) {
			xCord[1] = xCord[1] - 1;
			xCord[2] = xCord[2] - 2;
			yCord[0] = yCord[0] - 1;
			yCord[2] = yCord[2] + 1;
			yCord[3] = yCord[3] + 1;
		}
		if (versionNo == 2) {
			xCord[1] = xCord[1] + 1;
			xCord[2] = xCord[2] + 2;
			yCord[0] = yCord[0] + 1;
			yCord[2] = yCord[2] - 1;
			yCord[3] = yCord[3] + 1;
		}
		if (versionNo == 3) {
			xCord[0] = xCord[0] + 1;
			xCord[2] = xCord[2] - 1;
			xCord[3] = xCord[3] - 1;
			yCord[0] = yCord[0] - 1;
			yCord[2] = yCord[2] + 1;
			yCord[3] = yCord[3] - 1;
		}
		if (versionNo == 4) {
			xCord[0] = xCord[0] - 1;
			xCord[2] = xCord[2] + 1;
			xCord[3] = xCord[3] + 1;
			yCord[0] = yCord[0] + 1;
			yCord[2] = yCord[2] - 1;
			yCord[3] = yCord[3] - 1;
		}
	}

	public void changeVersionClock(int versionNo) {
		super.changeVersion(versionNo);
		if (versionNo == 1) {
			xCord[1] = xCord[1] - 1;
			xCord[2] = xCord[2] - 2;
			yCord[0] = yCord[0] - 1;
			yCord[2] = yCord[2] + 1;
			yCord[3] = yCord[3] - 1;
		} else if (versionNo == 2) {
			xCord[0] = xCord[0] - 1;
			xCord[2] = xCord[2] + 1;
			xCord[3] = xCord[3] + 1;
			yCord[0] = yCord[0] + 1;
			yCord[2] = yCord[2] - 1;
			yCord[3] = yCord[3] + 1;
		} else if (versionNo == 3) {
			xCord[0] = xCord[0] + 1;
			xCord[2] = xCord[2] - 1;
			xCord[3] = xCord[3] - 1;
			yCord[0] = yCord[0] - 1;
			yCord[2] = yCord[2] + 1;
			yCord[3] = yCord[3] + 1;
		} else if (versionNo == 4) {
			xCord[1] = xCord[1] + 1;
			xCord[2] = xCord[2] + 2;
			yCord[0] = yCord[0] + 1;
			yCord[2] = yCord[2] - 1;
			yCord[3] = yCord[3] - 1;
		}
	}
}

class LShape extends Version {
	public static int boardLength = 20;

	LShape() {
		Random r = new Random();
		int ranNo = r.nextInt(((boardLength - 5) - 5) + 1) + 5;
		xCord = new int[] { 1, 2, 3, 3 };
		yCord = new int[] { ranNo, ranNo, ranNo, ranNo + 1 };
	}

	public boolean checkDown(char board[][]) {
		if (versionNo == 1 && (board[xCord[2] + 1][yCord[2]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')) {
			return true;
		} else if (versionNo == 2 && (board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[1] + 1][yCord[1]] == '#'
				|| board[xCord[2] + 1][yCord[2]] == '#')) {
			return true;
		} else if (versionNo == 3 && (board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')) {
			return true;
		} else if (versionNo == 4 && (board[xCord[0] + 1][yCord[0]] == '#' || board[xCord[1] + 1][yCord[1]] == '#'
				|| board[xCord[2] + 1][yCord[2]] == '#')) {
			return true;
		}
		return false;
	}

	public boolean checkLeft(char board[][]) {
		if (versionNo == 1 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#'
				|| board[xCord[2]][yCord[2] - 1] == '#')) {
			return true;
		} else if (versionNo == 2 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		} else if (versionNo == 3 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#'
				|| board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		} else if (versionNo == 4 && (board[xCord[2]][yCord[2] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		}
		return false;
	}

	public boolean checkRight(char board[][]) {
		if (versionNo == 1 && (board[xCord[0]][yCord[0] + 1] == '#' || board[xCord[1]][yCord[1] + 1] == '#'
				|| board[xCord[3]][yCord[3] + 1] == '#')) {
			return true;
		} else if (versionNo == 2 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		} else if (versionNo == 3 && (board[xCord[0]][yCord[0] + 1] == '#' || board[xCord[1]][yCord[1] + 1] == '#'
				|| board[xCord[2]][yCord[2] + 1] == '#')) {
			return true;
		} else if (versionNo == 4 && (board[xCord[2]][yCord[2] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		}
		return false;
	}

	public void changeVersionAnticlock(int versionNo) {
		super.changeVersion(versionNo);
		if (versionNo == 1) {
			xCord[1] = xCord[1] + 1;
			xCord[2] = xCord[2] + 2;
			xCord[3] = xCord[3] + 1;
			yCord[0] = yCord[0] - 2;
			yCord[1] = yCord[1] - 1;
			yCord[3] = yCord[3] + 1;
		} else if (versionNo == 2) {
			xCord[0] = xCord[0] + 2;
			xCord[1] = xCord[1] + 1;
			xCord[3] = xCord[3] - 1;
			yCord[1] = yCord[1] + 1;
			yCord[2] = yCord[2] + 2;
			yCord[3] = yCord[3] + 1;
		} else if (versionNo == 3) {
			xCord[1] = xCord[1] - 1;
			xCord[2] = xCord[2] - 2;
			xCord[3] = xCord[3] - 1;
			yCord[0] = yCord[0] + 2;
			yCord[1] = yCord[1] + 1;
			yCord[3] = yCord[3] - 1;
		} else if (versionNo == 4) {
			xCord[0] = xCord[0] - 2;
			xCord[1] = xCord[1] - 1;
			xCord[3] = xCord[3] + 1;
			yCord[1] = yCord[1] - 1;
			yCord[2] = yCord[2] - 2;
			yCord[3] = yCord[3] - 1;
		}
	}

	public void changeVersionClock(int versionNo) {
		super.changeVersion(versionNo);
		if (versionNo == 1) {
			xCord[0] = xCord[0] - 2;
			xCord[1] = xCord[1] - 1;
			xCord[3] = xCord[3] + 1;
			yCord[1] = yCord[1] - 1;
			yCord[2] = yCord[2] - 2;
			yCord[3] = yCord[3] - 1;
		} else if (versionNo == 2) {
			xCord[1] = xCord[1] + 1;
			xCord[2] = xCord[2] + 2;
			xCord[3] = xCord[3] + 1;
			yCord[0] = yCord[0] - 2;
			yCord[1] = yCord[1] - 1;
			yCord[3] = yCord[3] + 1;
		} else if (versionNo == 3) {
			xCord[0] = xCord[0] + 2;
			xCord[1] = xCord[1] + 1;
			xCord[3] = xCord[3] - 1;
			yCord[1] = yCord[1] + 1;
			yCord[2] = yCord[2] + 2;
			yCord[3] = yCord[3] + 1;
		} else if (versionNo == 4) {
			xCord[1] = xCord[1] - 1;
			xCord[2] = xCord[2] - 2;
			xCord[3] = xCord[3] - 1;
			yCord[0] = yCord[0] + 2;
			yCord[1] = yCord[1] + 1;
			yCord[3] = yCord[3] - 1;
		}
	}
}

class ZShape extends Version {
	public static int boardLength = 20;

	ZShape() {
		Random r = new Random();
		int ranNo = r.nextInt(((boardLength - 5) - 5) + 1) + 5;
		xCord = new int[] { 1, 2, 2, 3 };
		yCord = new int[] { ranNo, ranNo, ranNo + 1, ranNo + 1 };
	}

	public boolean checkDown(char board[][]) {
		if ((versionNo == 1 || versionNo == 3)
				&& (board[xCord[1] + 1][yCord[1]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')) {
			return true;
		} else if ((versionNo == 2 || versionNo == 4) && (board[xCord[0] + 1][yCord[0]] == '#'
				|| board[xCord[2] + 1][yCord[2]] == '#' || board[xCord[3] + 1][yCord[3]] == '#')) {
			return true;
		}
		return false;
	}

	public boolean checkLeft(char board[][]) {
		if (versionNo == 1 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[1]][yCord[1] - 1] == '#'
				|| board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		} else if (versionNo == 2 && (board[xCord[1]][yCord[1] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		} else if (versionNo == 3 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#'
				|| board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		} else if (versionNo == 4 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#')) {
			return true;
		}
		return false;
	}

	public boolean checkRight(char board[][]) {
		if (versionNo == 1 && (board[xCord[0]][yCord[0] + 1] == '#' || board[xCord[2]][yCord[2] + 1] == '#'
				|| board[xCord[3]][yCord[3] + 1] == '#')) {
			return true;
		} else if (versionNo == 2 && (board[xCord[0]][yCord[0] - 1] == '#' || board[xCord[2]][yCord[2] - 1] == '#')) {
			return true;
		} else if (versionNo == 3 && (board[xCord[0]][yCord[0] + 1] == '#' || board[xCord[1]][yCord[1] + 1] == '#'
				|| board[xCord[3]][yCord[3] + 1] == '#')) {
			return true;
		} else if (versionNo == 4 && (board[xCord[1]][yCord[1] - 1] == '#' || board[xCord[3]][yCord[3] - 1] == '#')) {
			return true;
		}
		return false;
	}

	public void changeVersionAnticlock(int versionNo) {
		super.changeVersion(versionNo);
		if (versionNo == 1 || versionNo == 3) {
			xCord[1] = xCord[1] + 1;
			xCord[3] = xCord[3] + 1;
			yCord[0] = yCord[0] - 2;
			yCord[1] = yCord[1] - 1;
			yCord[3] = yCord[3] + 1;
		} else if (versionNo == 2 || versionNo == 4) {
			xCord[1] = xCord[1] - 1;
			xCord[3] = xCord[3] - 1;
			yCord[0] = yCord[0] + 2;
			yCord[1] = yCord[1] + 1;
			yCord[3] = yCord[3] - 1;
		}
	}

	public void changeVersionClock(int versionNo) {
		super.changeVersion(versionNo);
		changeVersionAnticlock(versionNo);
	}
}

class NewState {

	public BoardClass board;
	public Version currentShape;
	public 	int xCord[];
	public int yCord[];
	public Stack<String> undoMovement = new Stack<String>();
	public Stack<String> redoMovement = new Stack<String>();
	public int currVersion;

	NewState(BoardClass board, Version currentShape, Stack<String> undoMovement, Stack<String> redoMovement, int currVersion) {
		this.board = board;
		xCord=currentShape.xCord;
		yCord=currentShape.yCord;
		this.currentShape = currentShape;
		this.undoMovement.addAll(undoMovement);
		this.redoMovement.addAll(redoMovement);
		this.currVersion = currVersion;
	}
}

public class Tetris {
	public static int boardLength = 20;
	public static BoardClass board = new BoardClass();
	public static int hashNo[] = new int[boardLength];
	static int currentVer = 1, currentShapeNo = 3;
	public static Stack<String> undoMovement = new Stack<String>();
	public static Stack<String> redoMovement = new Stack<String>();
	public static Stack<NewState> undoNewState = new Stack<NewState>();

	static boolean nextBlock = true;
	static Version currentShape;

	public static void main(String args[]) {
		System.out.println("->Main Activated ");
		undoMovement = new Stack<String>();
		redoMovement = new Stack<String>();
		undoNewState = new Stack<NewState>();
		Scanner sc = new Scanner(System.in);
		Line line1;
		Square s1;
		TShape t1;
		LShape l1;
		ZShape lt1;

		char dir;
		clearBoard();

		while (nextBlock) {
			line1 = new Line();
			s1 = new Square();
			t1 = new TShape();
			l1 = new LShape();
			lt1 = new ZShape();

			currentShapeNo = (int) (Math.random() * 5) + 1;
			nextBlock = false;
			currentShape = new Version();

			while (true) {
				currentShape = currentShapeNo == 1 ? line1 : currentShapeNo == 2 ? s1 : currentShapeNo == 3 ? t1 : currentShapeNo == 4 ? l1 : lt1;
				drawOnBoard(currentShape);
				displayBoard();
				dir = sc.next().charAt(0);
				if (dir == 'c' || dir == 'C') {
					currentVer++;
					currentVer = currentVer > 4 ? 1 : currentVer;
					clearFromBoard(currentShape);
					currentShape.changeVersionClock(currentVer);
					undoMovement.push("r");
				} else if (dir == 'r' || dir == 'R') {
					currentVer--;
					currentVer = currentVer >= 1 ? currentVer : 4;
					undoMovement.push("c");
					clearFromBoard(currentShape);
					currentShape.changeVersionAnticlock(currentVer);
				} else if (dir == 'a' || dir == 'A') {
					moveLeft(currentShape);
					if (nextBlock != true)
						undoMovement.push("a");
				} else if (dir == 'd' || dir == 'D') {
					moveRight(currentShape);
					undoMovement.push("d");
				} else if (dir == 's' || dir == 'S') {
					moveDown(currentShape);
					if (nextBlock != true)
						undoMovement.push("s");
				} else if (dir == 'u' || dir == 'U') {
					if (undoMovement.isEmpty())
						continue;
					undoStep(undoMovement.peek(), currentShape);
					redoMovement.push(undoMovement.pop());
				} else if (dir == 'n') {
					if (redoMovement.isEmpty())
						continue;
					redoStep(redoMovement.peek(), currentShape);
					undoMovement.push(redoMovement.pop());
				} else if (dir == 'q' || dir == 'Q') {
					System.exit(0);
				}

				if (nextBlock == true) {
					checkAndChangeToBoard(currentShape);
					checkRemoval(currentShape);
					break;
				}
			}
		}
		sc.close();
	}

	public static void clearFromBoard(Version V) {
		System.out.println("->clearFromBoard ");
		for (int i = 0; i < V.xCord.length; i++) {
			board.board[V.xCord[i]][V.yCord[i]] = ' ';
		}
	}

	public static void checkRemoval(Version V) {
		System.out.println("->checkRemoval ");
		for (int i = 0; i < 4; i++) {
			hashNo[board.board.length - 1 - V.xCord[i]]++;
		}
		for (int i = boardLength - 1; i > 0; i--) {
			if (hashNo[i] >= (boardLength - 2)) {
				for (int j = board.board.length - 1 - i; j > 0; j--) {
					board.board[j] = board.board[j - 1];
				}
				board.board[0] = new char[boardLength];
			}
		}
	}

	public static void clearBoard() {
		System.out.println("->clearBoard ");
		for (int i = 0; i < board.board.length; i++) {
			for (int j = 0; j < board.board.length; j++) {
				if (i == 0 || j == 0 || i == board.board.length - 1 || j == board.board.length - 1)
					board.board[i][j] = '*';
				else
					board.board[i][j] = ' ';
			}
		}
	}

	public static void clearScreen() {
		System.out.println("->clearScreen ");
		System.out.print("\033[H\033[2J");
	}

	public static void drawOnBoard(Version v1) {
		System.out.println("->drawOnBoard ");
		for (int i = 0; i < v1.xCord.length; i++) {
			board.board[v1.xCord[i]][v1.yCord[i]] = '#';
		}
	}

	public static void displayBoard() {
		System.out.println("->displayBoard ");
		for (int i = 0; i < boardLength; i++) {
			for (int j = 0; j < boardLength; j++) {
				System.out.print(" " + board.board[i][j]);
			}
			System.out.println();
		}
	}

	public static void moveDown(Version V) {
		System.out.println("->moveDown ");
		if ((V.xCord[0] == (boardLength - 2) || V.xCord[1] == (boardLength - 2) || V.xCord[2] == (boardLength - 2)
				|| V.xCord[3] == (boardLength - 2)) || V.checkDown(board.board)) {
			nextBlock = true;
		}
		else {
			for (int i = 0; i < V.xCord.length; i++) {
				board.board[V.xCord[i]][V.yCord[i]] = ' ';
				V.xCord[i]++;
			}
			System.out.println("== moved Down ");
		}
	}

	public static void moveLeft(Version V) {
		System.out.println("->moveLeft ");
		if (V.yCord[0] == 1 || V.yCord[1] == 1 || V.yCord[2] == 1 || V.yCord[3] == 1 || V.checkLeft(board.board)) {
			return;
		} else { 
			for (int i = 0; i < V.xCord.length; i++) {
				board.board[V.xCord[i]][V.yCord[i]] = ' ';
				V.yCord[i]--;
			}
			System.out.println("== moved Left ");
		}
	}

	public static void moveRight(Version V) {
		System.out.println("->moveRight ");
		if (V.yCord[0] == ( Tetris.boardLength - 1) || V.yCord[1] == (Tetris.boardLength - 2) || V.yCord[2] == (boardLength - 1)
				|| V.yCord[3] == (boardLength - 2) || V.checkRight(board.board)) {
			return;
		} else {
			for (int i = 0; i < V.xCord.length; i++) {
				board.board[V.xCord[i]][V.yCord[i]] = ' ';
				V.yCord[i]++;
			}
			System.out.println("== moved Right ");
		}
	}

	public static void checkAndChangeToBoard(Version V) {
		System.out.println("->checkAndChangeToBoard ");
		undoNewState.push(new NewState(board, V, undoMovement, redoMovement, currentVer));
		undoMovement.push("old");
		for (int i = 0; i < V.xCord.length; i++) {
			board.board[V.xCord[i]][V.yCord[i]] = '#';
		}
	}

	public static void undoStep(String dir, Version V) {
		System.out.println("->undoStep : "+dir);
		if (dir.equals("s")) {
			for (int i = 0; i < V.xCord.length; i++) {
				board.board[V.xCord[i]][V.yCord[i]] = ' ';
				V.xCord[i]--;
			}
		} else if (dir.equals("a")) {
			moveRight(V);
		} else if (dir.equals("d")) {
			moveLeft(V);
		} else if (dir.equals("n")) {
			currentVer--;
			V.changeVersion(currentVer);
		} else if (dir.equals("old")) {
			if (!undoNewState.empty()) {
				NewState newstate = undoNewState.pop();
				board = newstate.board;
				System.out.println("---" + board.board[1][1] + " " + V.xCord[0]);
				currentShape = newstate.currentShape;
				currentVer = newstate.currVersion;
				currentShape.xCord = newstate.xCord;
				currentShape.yCord = newstate.yCord;
				undoMovement = newstate.undoMovement;
				redoMovement = newstate.redoMovement;
			}
		}
	}

	public static void redoStep(String dir, Version V) {
		System.out.println("->redoStep : "+dir);
		if (dir.equals("s")) {
			moveDown(V);
		} else if (dir.equals("a")) {
			moveLeft(V);
		} else if (dir.equals("d")) {
			moveRight(V);
		} else if (dir.equals("c")) {
			currentVer++;
			V.changeVersion(currentVer);
		}
	}
}