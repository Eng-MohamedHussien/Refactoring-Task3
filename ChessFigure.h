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
  Rook(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};

class Knight : public ChessFigure {
  Knight(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};

class Bishop : public ChessFigure {
  Bishop(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};

class Pawn : public ChessFigure {
  Pawn(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};

class King : public ChessFigure {
  King(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};

class Queen : public ChessFigure {
  Queen(const std::string &coord) : ChessFigure(coord) {}
  void Move(const std::string &nextCoord) override;
};
