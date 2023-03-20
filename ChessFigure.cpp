#include "ChessFigure.h"
#include <cassert>
#include <cmath>
#include <string>

using namespace std;

const char ChessFigure::StartRowIndex = 'A';
const char ChessFigure::EndRowIndex = 'H';
const char ChessFigure::StartColumnIndex = '1';
const char ChessFigure::EndColumnIndex = '8';

ChessFigure::ChessFigure(const std::string &coord) : currentCoord(coord) {}

bool inRangeMove(const std::string &nextCoord) {
  return nextCoord[0] >= ChessFigure::StartRowIndex &&
         nextCoord[0] <= ChessFigure::EndRowIndex &&
         nextCoord[1] >= ChessFigure::StartColumnIndex &&
         nextCoord[1] <= ChessFigure::EndColumnIndex;
}

bool isValidRookMove(const std::string &currentCoord,
                     const std::string &nextCoord) {
  return !(
      (nextCoord[0] != currentCoord[0]) && (nextCoord[1] != currentCoord[1]) ||
      ((nextCoord[0] == currentCoord[0]) && (nextCoord[1] == currentCoord[1])));
}

bool isValidKnightMove(const std::string &currentCoord,
                       const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);
  return (dx == 1 && dy == 2 || dx == 2 && dy == 1);
}

bool isValidBishopMove(const std::string &currentCoord,
                       const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);
  return dx == dy;
}

bool isValidKingMove(const std::string &currentCoord,
                     const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);
  return dx <= 1 && dy <= 1;
}

bool isValidQueenMove(const std::string &currentCoord,
                      const std::string &nextCoord) {
  int dx, dy;
  dx = abs(nextCoord[0] - currentCoord[0]);
  dy = abs(nextCoord[1] - currentCoord[1]);

  return dx == dy || nextCoord[0] == currentCoord[0] ||
         nextCoord[1] == currentCoord[1];
}

bool isValidPawnMove(const std::string &currentCoord,
                     const std::string &nextCoord) {
  int dy = abs(nextCoord[1] - currentCoord[1]);
  return !(nextCoord[0] != currentCoord[0] || nextCoord[1] <= currentCoord[1] ||
           (dy != 1 && (currentCoord[1] != '2' || nextCoord[1] != '4')));
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