#pragma once

#include <memory>
#include <string>

#include <userver/compiler/select.hpp>
#include <userver/engine/subprocess/process_starter.hpp>
#include <userver/engine/task/task_processor_fwd.hpp>
#include <userver/formats/parse/to.hpp>
#include <userver/utils/fast_pimpl.hpp>

namespace svh::video::logic::convert::controller {

namespace impl {
class ConvertControllerImpl;
class ConvertConfig;
}  // namespace impl

class ConfigBuilder {
 public:
  ConfigBuilder();
  std::unique_ptr<impl::ConvertConfig> Make();

 private:
  std::unique_ptr<impl::ConvertConfig> config_;
};

class ConvertController {
 public:
  ConvertController(userver::engine::TaskProcessor&,
                    userver::engine::subprocess::ProcessStarter&,
                    std::unique_ptr<impl::ConvertConfig>);

  ~ConvertController();

  ConvertController(const ConvertController&) = delete;
  ConvertController(ConvertController&&) = delete;
  ConvertController& operator=(const ConvertController&) = delete;
  ConvertController& operator=(ConvertController&&) = delete;

  void enqueue(std::string, std::string);

 private:
  constexpr static auto kImplSize =
      userver::compiler::SelectSize().For64Bit(344);
  constexpr static auto kImplAlignment =
      userver::compiler::SelectSize().For64Bit(8);
  userver::utils::FastPimpl<impl::ConvertControllerImpl, kImplSize,
                            kImplAlignment>
      impl_;
};

}  // namespace svh::video::logic::convert::controller