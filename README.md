# Overview

This project consists of two mechanisms: a Launcher and a Dropper. The Launcher sends an RF signal to the Dropper to initiate the drop sequence while simultaneously activating a relay to release compressed air, launching the projectile.

## Components

### Launcher

* Arduino: Controls the system.
* RF Transmitter: Sends a signal to the Dropper.
* Relay Module: Activates the solenoid for launching.

### Dropper

* Arduino: Receives the RF signal.
* RF Receiver: Listens for the signal from the Launcher.
* Dropping Mechanism: Releases the plushy when triggered.

### How It Works

1. The Launcher is activated through the serial monitor.
2. It sends an RF signal to the Dropper and activates the relay.
3. The Dropper releases the plushy, and the Launcher fires the projectile using compressed air.
