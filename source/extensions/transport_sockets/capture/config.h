#pragma once

#include "envoy/server/transport_socket_config.h"

#include "extensions/transport_sockets/well_known_names.h"

namespace Envoy {
namespace Extensions {
namespace TransportSockets {
namespace Capture {

/**
 * Config registration for the capture wrapper for transport socket factory.
 * @see TransportSocketConfigFactory.
 */
class CaptureSocketConfigFactory
    : public virtual Server::Configuration::TransportSocketConfigFactory {
public:
  virtual ~CaptureSocketConfigFactory() {}
  std::string name() const override { return TransportSocketNames::get().CAPTURE; }
  ProtobufTypes::MessagePtr createEmptyConfigProto() override;
};

class UpstreamCaptureSocketConfigFactory
    : public Server::Configuration::UpstreamTransportSocketConfigFactory,
      public CaptureSocketConfigFactory {
public:
  Network::TransportSocketFactoryPtr createTransportSocketFactory(
      const Protobuf::Message& config,
      Server::Configuration::TransportSocketFactoryContext& context) override;
};

class DownstreamCaptureSocketConfigFactory
    : public Server::Configuration::DownstreamTransportSocketConfigFactory,
      public CaptureSocketConfigFactory {
public:
  Network::TransportSocketFactoryPtr createTransportSocketFactory(
      const std::string& listener_name, const std::vector<std::string>& server_names,
      bool skip_context_update, const Protobuf::Message& config,
      Server::Configuration::TransportSocketFactoryContext& context) override;
};

} // namespace Capture
} // namespace TransportSockets
} // namespace Extensions
} // namespace Envoy
