#pragma once
#include <string>
class ChessFigure {

public:
  ChessFigure(const std::string &coord);
  virtual void Move(const std::string &nextCoord) = 0;

protected:
  std::string currentCoord;
};

class Rook : public ChessFigure {
public:
  Rook(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};

class Knight : public ChessFigure {
public:
  Knight(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};

class Bishop : public ChessFigure {
public:
  Bishop(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};

class Pawn : public ChessFigure {
public:
  Pawn(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};

class King : public ChessFigure {
public:
  King(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};

class Queen : public ChessFigure {
public:
  Queen(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};
