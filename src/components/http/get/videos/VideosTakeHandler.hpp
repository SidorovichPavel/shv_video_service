#pragma once

#include <string_view>

#include <userver/server/handlers/http_handler_json_base.hpp>
#include <userver/storages/postgres/cluster.hpp>

namespace svh::video::components::http::get::videos {

class VideosTakeHandler final
    : public userver::server::handlers::HttpHandlerJsonBase {
 public:
  constexpr static std::string_view kName = "videos-take-handler";

  VideosTakeHandler(const userver::components::ComponentConfig& cfg,
                    const userver::components::ComponentContext& ctx);

  userver::formats::json::Value HandleRequestJsonThrow(
      const userver::server::http::HttpRequest& request,
      const userver::formats::json::Value& request_json,
      userver::server::request::RequestContext& request_context) const override;

 private:
  void EnableCORS(const userver::server::http::HttpRequest& request) const;

  userver::storages::postgres::ClusterPtr pg_cluster_;
};

}  // namespace svh::video::components::http::get::videos