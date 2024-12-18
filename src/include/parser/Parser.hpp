#pragma once

#include "common/Context.hpp"
#include "common/Instance.hpp"
#include "common/ResultSet.hpp"
#include "common/Status.hpp"
#include "common/util/StringUtil.hpp"
#include "parser/Checker.hpp"
#include "parser/Lexer.hpp"

#include <memory>
#include <string_view>

namespace DB {
class Parser : public Instance<Parser> {
  Checker checker_;

protected:
  std::shared_ptr<Instance<Checker>> GetChecker() {
    return checker_.GetInstance();
  }

public:
  Parser();

  Status Parse(std::string_view query, std::shared_ptr<QueryContext> context,
               ResultSet &result_set);

  Status ParseCreate(Lexer &lexer, std::shared_ptr<QueryContext> context,
                     ResultSet &result_set);

  Status ParseDrop(Lexer &lexer, std::shared_ptr<QueryContext> context,
                   ResultSet &result_set);

  Status ParseShow(Lexer &lexer, std::shared_ptr<QueryContext> context,
                   ResultSet &result_set);

  Status ParseUse(Lexer &lexer, std::shared_ptr<QueryContext> context,
                  ResultSet &result_set);

  Status CreateTable(Lexer &lexer, std::shared_ptr<QueryContext> context);
};
} // namespace DB