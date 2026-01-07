*This project has been created as part of the 42 curriculum by arabdull*  

# Born2BeRoot

## Description

**Born2BeRoot** is a Linux administration project aimed at teaching system setup, configuration, and security best practices.  

The main goal was set up an operating system in virtual machine while implementing strict rules.

**Design choices made during setup:**

- **Partitioning:** Root, Home, and Swap partitions for better system management.  
- **Security policies:** SSH hardening, firewall configuration, stong password policies.  
- **User management:** Non-root administrative user created with sudo privileges.
- **Services installed:** UFW, SSH 

---

## OS Choice Comparison

| Feature | Debian | Rocky Linux |
|---------|--------|-------------|
| Stability | Very stable, large community, frequent updates | Enterprise-focused, very stable, slower updates |
| Package manager | APT (.deb) | DNF / YUM (.rpm) |
| Documentation | Extensive, beginner-friendly | Enterprise-focused, less beginner resources |
| Use case | Educational, server, desktop | Enterprise Linux servers, production systems |

**Choice:** Debian was chosen for this project because of its stability and large documentation base.  

---

## Security Framework Comparison

| Feature | AppArmor | SELinux |
|---------|---------|---------|
| Integration | Default in Debian | Default in RedHat/Rocky |
| Complexity | Easier to configure | More granular, complex policies |
| Use case | Educational projects, small/medium servers | Enterprise-grade security |

**Choice:** AppArmor was used due to its simpler setup for educational purposes.  

---

## Firewall Comparison

| Feature | UFW | firewalld |
|---------|-----|-----------|
| Ease of use | Simple CLI commands | Slightly more complex, dynamic zones |
| Default | Debian | RHEL/Rocky Linux |
| Use case | Quick firewall configuration | Enterprise setups with multiple zones |

**Choice:** UFW was chosen for its simplicity and suitability for a learning environment.  

---

## Virtualization Comparison

| Feature | VirtualBox | UTM |
|---------|------------|-----|
| Platform | Cross-platform, widely used | macOS, iOS focus |
| Features | Snapshots, GUI, shared folders | Lightweight, ARM support |
| Use case | Educational labs, testing | macOS native, lightweight VM testing |

**Choice:** VirtualBox was used due to its cross-platform support and ease of use in a lab environment.  

---

## Instructions

Check the hashsum of VM before start
```
shasum Born2beroot.vdi
```

Clone original VM to prevent changing the hashsum
```
VBoxManage clonevm "Born2beroot" --name "Born2beroot_clone" --register --mode all --basefolder "/nfs/homes/arabdull/goinfre"

```

Run clone of main VM not to ruin the hashsum for further evaluations:
```
VBoxManage startvm "Born2beroot_clone"
```

## Resourses

- [Debian Official Doc](https://www.debian.org/doc/)
- [Linux Command Reference](https://linuxcommand.org/)
- [UFW](https://help.ubuntu.com/community/UFW)
- [SSH](https://www.ssh.com/)
- [AppArmor](https://apparmor.net/)
- [Guidebook](https://noreply.gitbook.io/born2beroot)
- man PAM
- man pam_pwquality

## AI usage
This README.md has been partially made by ChatGPT. Also monitoring script was debugged and checked with AI.
