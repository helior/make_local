## Drush Make Local
Allows you the ability to use a local directory as a download source for your projects. This is useful since the `file` download type doesn't support downloading local paths that aren't first archived (.tar.gz format).

### Installation
Run `drush dl make_local-6.x-1.0`, or manually download to your `~/.drush` directory.

### Usage
```
projects[internal_installation_profile][type] = profile
projects[internal_installation_profile][download][type] = local
projects[internal_installation_profile][download][source] = ../path/to/internal_installation_profile
projects[internal_installation_profile][version] = 7.x-1.x
```

This also provides a "local" project type, so that you can include arbitrary local directories into your drupal site:

```
projects[drush][type] = local
projects[drush][download][type] = local
projects[drush][download][source] = path/to/your/drush/commands
projects[drush][subdir] = sites/all     ; will move your drush commands to sites/all/drush
```


### Compatibility
The 6.x-1.x branch is compatible with Drush 5.x/6.x.
