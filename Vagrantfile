
Vagrant.configure("2") do |config|

    config.vm.box = "bento/ubuntu-20.04"
  
    config.vm.define "test" do |machine1|
      machine1.vm.hostname = "test"
  
      machine1.vm.network "private_network", ip: "192.168.56.10"
      
      machine1.vm.synced_folder ".", "/home/vagrant/data-structures/"
      machine1.vm.synced_folder ".", "/vagrant", disabled: true
      machine1.vm.provision "shell", path: "scripts/bootstrap.sh"
      machine1.vm.provider "virtualbox" do |vb|
        vb.name = "test"
        vb.memory = "8192"
        vb.cpus = "1"
      end
    end
  end
  