#include "ChessFigure.h"
#include <cassert>
#include <cmath>
#include <string>

using namespace std;

ChessFigure::ChessFigure(const std::string &coord) : currentCoord(coord) {}

bool inRangeMove(const std::string &nextCoord) {
  return nextCoord[0] >= 'A' && nextCoord[0] <= 'H' && nextCoord[1] >= '1' &&
         nextCoord[1] <= '8';
}

// Can move in its line or row
bool isValidRookMove(const std::string &currentCoord,
                     const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);
  return (dx >= 1 && dy == 0) || (dx == 0 && dy >= 1);
}

// L shape
bool isValidKnightMove(const std::string &currentCoord,
                       const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);
  return (dx == 1 && dy == 2) || (dx == 2 && dy == 1);
}

// Moves diagonally
bool isValidBishopMove(const std::string &currentCoord,
                       const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);
  return dx == dy && dx > 0 && dy > 0;
}

// Moves from its square to a neighboring square
bool isValidKingMove(const std::string &currentCoord,
                     const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);
  return (dx == 1 && dy == 0) || (dy == 1 && dx == 0);
}

// May move like a Rook or a Bishop
bool isValidQueenMove(const std::string &currentCoord,
                      const std::string &nextCoord) {

  bool rookMove = isValidRookMove(currentCoord, nextCoord);
  bool bishopMove = isValidBishopMove(currentCoord, nextCoord);

  return (rookMove && !bishopMove) || (!rookMove && bishopMove);
}

// Pawn moves 1 spuare straight ahead or 2 squares straight ahead at the
// beginning
bool isValidPawnMove(const std::string &currentCoord,
                     const std::string &nextCoord) {
  int dy = nextCoord[1] - currentCoord[1];
  return nextCoord[0] == currentCoord[0] &&
         (dy == 1 ||
          (dy == 2 && currentCoord[1] == '2' && nextCoord[1] == '4'));
}

void Rook::Move(const std::string &nextCoord) {
  if (!inRangeMove(nextCoord)) {
    throw "Out of range Move !!!";
  }
  if (!isValidRookMove(currentCoord, nextCoord)) {
    throw "Invalid Move !!!";
  }
  currentCoord = nextCoord;
}

void Knight::Move(const std::string &nextCoord) {
  if (!inRangeMove(nextCoord)) {
    throw "Out of range Move !!!";
  }
  if (!isValidKnightMove(currentCoord, nextCoord)) {
    throw "Invalid Move !!!";
  }
  currentCoord = nextCoord;
}

void Bishop::Move(const std::string &nextCoord) {
  if (!inRangeMove(nextCoord)) {
    throw "Out of range Move !!!";
  }
  if (!isValidBishopMove(currentCoord, nextCoord)) {
    throw "Invalid Move !!!";
  }
  currentCoord = nextCoord;
}

void Pawn::Move(const std::string &nextCoord) {
  if (!inRangeMove(nextCoord)) {
    throw "Out of range Move !!!";
  }
  if (!isValidPawnMove(currentCoord, nextCoord)) {
    throw "Invalid Move !!!";
  }
  currentCoord = nextCoord;
}

void King::Move(const std::string &nextCoord) {
  if (!inRangeMove(nextCoord)) {
    throw "Out of range Move !!!";
  }
  if (!isValidKingMove(currentCoord, nextCoord)) {
    throw "Invalid Move !!!";
  }
  currentCoord = nextCoord;
}

void Queen::Move(const std::string &nextCoord) {
  if (!inRangeMove(nextCoord)) {
    throw "Out of range Move !!!";
  }
  if (!isValidQueenMove(currentCoord, nextCoord)) {
    throw "Invalid Move !!!";
  }
  currentCoord = nextCoord;
}