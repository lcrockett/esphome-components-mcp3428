#pragma once

#include "esphome/core/component.h"
#include "esphome/core/helpers.h"
#include "esphome/core/hal.h"

#include "esphome/components/sensor/sensor.h"

#include "../mcp3428.h"

namespace esphome {
namespace mcp3428 {

/// Internal holder class that is in instance of Sensor so that the hub can create individual sensors.
class MCP3428Sensor : public sensor::Sensor,
                      public PollingComponent,
                      public Parented<MCP3428Component> {
 public:
  void set_multiplexer(MCP3428Multiplexer multiplexer) { this->multiplexer_ = multiplexer; }
  void set_gain(MCP3428Gain gain) { this->gain_ = gain; }
  void set_resolution(MCP3428Resolution resolution) { this->resolution_ = resolution; }

  void setup() override;
  void dump_config() override;
  void update() override;

  float sample();

 protected:
  MCP3428Multiplexer multiplexer_;
  MCP3428Gain gain_;
  MCP3428Resolution resolution_;
};

}  // namespace mcp3428
}  // namespace esphome
