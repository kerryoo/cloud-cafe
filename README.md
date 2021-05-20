# Cloud Cafe

## Introduction
Cloud Cafe is a basic, distributed game server implemented with a cluster of cloud computers.


## Motivation

The two architectures for server based video games are the client-server model and the peer to peer model. The client-server model faces problems with network delays, scalability, and over/under-provisioning, while the peer to peer model has problems with security and resource management. Cloud Cafe is a new approach to game server architecture. Through leveraging pre-existing technologies that elastically provision resources to cloud computers and manipulating client states strictly within the cluster, this model may alleviate the previously mentioned problems. Even though it is undetermined if such an implementation is suitable, it seems investigating this model is worthwhile.

## Features
This first iteration of Cloud Cafe features basic operations of the client-server architecture:
* Client inputs are sent to server, which then broadcasts the updated client state to all clients.
* Clients can log in/out, chat, and move.
* Client data can be stored and manipulated on a separate cloud computer.

## Implementation and Technologies

The current implementation relies heavily on Confluent Kafka to relay messages between the client and the server. The client uses Unity, C#, and .NET to produce a message containing the requested state transformation and posts it to a topic. The server, which uses C++, consumes the message, transforms that client's state, and produces a message to broadcast the new client state to all users. Users asynchronously consume the message and update their screens accordingly.

Ansible playbooks are used to provision the cloud computers, which are hosted on AWS EC2. CouchDB is used to store client data.

## Installation
Use the automation tool [ansible](https://docs.ansible.com/ansible/latest/installation_guide/intro_installation.html) to provision the cloud computer server. You will need to set environment variables (based on your EC2 settings):
* aws_access_key
* aws_secret_key
* aws_security_token
* key_name
* region
* group
* subnet_id

To create the cloud computer running CouchDB use:
```bash
ansible-playbook server-playbooks/create_couch_db_vm.yml
```

To create the cloud computer running the server use:
```bash
ansible-playbook server-playbooks/create_server_vm.yml
```

## Near Future and Ultimate Goals
Now that the project has basic server functionality, the goal is to take advantage of pre-existing cloud computing technologies to create more unique features, such as elastic provisioning. This will be done through creating a Kubernetes cluster.

After the core cloud features are integrated into the project, it will be useful to develop a more sophisticated server to test against the traditional server architectures. It will be interesting to explore different use cases for this cloud-based approach. If it is promising, then the ultimate goal is to turn Cloud Cafe into high-level networking library for Unity, where users can easily provision a server implementing this approach.
